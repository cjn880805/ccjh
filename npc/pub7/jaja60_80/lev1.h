#define LEV1_BEGIN(npc_name)	class npc_name : public CNlev1	{	public:	npc_name(){};	virtual ~npc_name(){};
#define LEV1_END		};	

NPC_BEGIN(CNlev1);

void die()
{
	char msg[255];
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(killer)
	{
		tell_object(killer, snprintf(msg, 255, "%s���ˡ�", name(1)));
		if( killer->Query(CChar::IS_USER))
		{
			if(killer->query("level")<=100 && killer->query("level")>=50)
			{
				int reward;
				
				reward=NK_Gain(killer, this);
				if(reward > 0)
				{
					//����NK����
					int nk_limit = killer->query("level") * 4 + 100;
					
					if(reward > nk_limit) reward = nk_limit;
					
					killer->add("kill/nkgain",reward);
					killer->add("combat_exp", reward);
					
					tell_object(killer, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", name(1), reward));
					//���ɳ�Ա����õľ���1%���׸��ػ�ʹ��
					if(killer->querymap("corps"))
					{
						CContainer * env = load_room(killer->querystr("corps/id"));
						switch(env->query("index"))
						{
						case 1:
							env=load_room(snprintf(msg, 255,"g1_���´��_%s",killer->querystr("corps/id")));
							break;
						}
						CNpc * sh = find_npc(env->query_temp("shizhe"));
						if(sh) 
						{
							((CChar *)sh)->add("combat_exp",reward/100);
							tell_object(killer, snprintf(msg, 255, "ͬʱ������%s������%d����ػ����飡", env->querystr("area"), reward/100));
						}
					}
				}
			}
		}
		killer->add("mks", 1);
		if( current_time < killer->query("tradepro/quest_time")
			&& killer->query("tradepro/index")==3
			&& EQUALSTR(killer->querystr("tradepro/quest_killnpc_id"), querystr("id")))
		{
			tell_object(killer,snprintf(msg, 255,  "\n$HIW��ϲ�������%sί���������\n",killer->query("tradepro/quest_npc_name")));
			killer->set("tradepro/quest_killnpc_ok",1);
		}
		if(killer->query("tradepro/index")==13 && query("combat_exp") >= killer->query("combat_exp")/15 )
		{
			CContainer * tradepro_item=load_item("tradepro_item");
			tradepro_item->set_name(killer->querystr("tradepro/quest_item_name"),"cai liao");
			tradepro_item->move(killer->environment());
		}
	}
/*	
	CContainer * obj=environment();
	CContainer * bot = load_item("corpse_ob");
	bot->set_name(snprintf(msg, 255, "%s��ʬ��", name(1)), "corpse");
	destruct(this);
	bot->move(obj);
*/	CNpc::die();
}

int NK_Gain(CChar * killer, CChar * victim)
{
	LONG eff_dx, reward, nkgain;
	//��ֹ�ε���NPC�������˵þ��顣
	if( DIFFERSTR(victim->querystr_temp("last_fainted_from"), killer->querystr("id")) ) return 0;
	
	//��NPC������
	if ( killer->query("level") < victim->query("level")) 
		killer->add("repute", - victim->query("repute") / 50);
	
    eff_dx = victim->query("eff_dx");
    nkgain=victim->query("nkgain");
	
    //����ɱͬ���ɵ�NPC�þ��顣
    if(killer->querymap("family") 
		&& EQUALSTR(killer->querystr("family/family_name"), victim->querystr("family/family_name")))
		return 0;
	
    eff_dx=victim->query("combat_exp");      
    
    if(!nkgain) 
	{
		LONG effdx = eff_dx;
		//180��~210��֮��
		if(effdx>2250000) 
			nkgain=320;
		else if(effdx>2180000)
			nkgain=300;
		else if(effdx>2120000)
			nkgain=255;
		else if(effdx>2060000)
			nkgain=195;
		else if(effdx>2000000)
			nkgain=150;
		else if(effdx>1940000)
			nkgain=99;
		else if(effdx>1880000)
			nkgain=75;
		else 
			nkgain = 50;//if(effdx>500)
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
		reward=100+random(150);
	return reward;   
}
NPC_END;