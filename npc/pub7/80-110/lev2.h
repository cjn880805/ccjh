#define LEV2_BEGIN(npc_name)	class npc_name : public CNlev2	{	public:	npc_name(){};	virtual ~npc_name(){};
#define LEV2_END		};	

NPC_BEGIN(CNlev2);

void die()
{
	char msg[255];
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(killer)
	{
		tell_object(killer, snprintf(msg, 255, "%s死了。", name(1)));
		if( killer->Query(CChar::IS_USER))
		{
			if(killer->query("level")<111 && killer->query("level")>80)
			{
				int reward;
				
				reward=NK_Gain(killer, this);
				if(reward > 0)
				{
					//设置NK上限
					int nk_limit = killer->query("level") * 4 + 100;
					
					if(reward > nk_limit) reward = nk_limit;
					
					killer->add("kill/nkgain",reward);
					killer->add("combat_exp", reward);
					
					tell_object(killer, snprintf(msg, 255, "你杀死%s获得%ld点NK经验！", name(1), reward));
				}
			}
		}
		killer->add("mks", 1);
	}
	
	CContainer * obj=environment();
	CContainer * bot = load_item("corpse_ob");
	bot->set_name(snprintf(msg, 255, "%s的尸体", name(1)), "corpse");
	destruct(this);
	bot->move(obj);
	//CNpc::die();
}

int NK_Gain(CChar * killer, CChar * victim)
{
	LONG eff_dx, reward, nkgain;
	//防止晕倒的NPC给其他人得经验。
	if( DIFFERSTR(victim->querystr_temp("last_fainted_from"), killer->querystr("id")) ) return 0;
	
	//得NPC的声望
	if ( killer->query("level") < victim->query("level")) 
		killer->add("repute", - victim->query("repute") / 50);
	
    eff_dx = victim->query("eff_dx");
    nkgain=victim->query("nkgain");
	
    //不能杀同门派的NPC得经验。
    if(killer->querymap("family") 
		&& EQUALSTR(killer->querystr("family/family_name"), victim->querystr("family/family_name")))
		return 0;
	
    eff_dx=victim->query("combat_exp");      
    
    if(!nkgain) 
	{
		LONG effdx = eff_dx;
		//250万~800万之间
		if(effdx>2250000) 
			nkgain=320;
		else if(effdx>2500000)
			nkgain=299;
		else if(effdx>3000000)
			nkgain=279;
		else if(effdx>3500000)
			nkgain=258;
		else if(effdx>4000000)
			nkgain=237;
		else if(effdx>4500000)
			nkgain=216;
		else if(effdx>5000000)
			nkgain=195;
		else if(effdx>5500000)
			nkgain=175;
		else if(effdx>6000000)
			nkgain=155;
		else if(effdx>6500000)
			nkgain=135;
		else if(effdx>7000000)
			nkgain=115;
		else if(effdx>7500000)
			nkgain=95;
		else if(effdx>8000000)
			nkgain=75;
		else 
			nkgain = 50;
		//if(effdx>500)
		//nkgain=25;
		//else nkgain=effdx / 20;
	}
	eff_dx=eff_dx*(120+random(80))/100;
	LONG dx = killer->query("combat_exp") * 2 / 3;
	double times = (double)(eff_dx - dx / 2) / (double)(dx + 1);
	if(times > 2) times = 2;
	if(times < 0) times = 0;
	reward = (LONG)(nkgain * times);
    
	if(reward<100)
		reward=100+random(50);
	return reward;   
}
NPC_END;