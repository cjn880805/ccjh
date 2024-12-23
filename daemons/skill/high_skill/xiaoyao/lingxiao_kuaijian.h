// lingxiao_kuaijian.h 凌霄快剑
//code by Teapot
//date : 2001-02-10

SKILL_BEGIN(CSlingxiao_kuaijian);

void create()
{
	set_name( "凌霄快剑");

	set("diff",150);
	Magic_t * magic;

	magic = add_magic("mixhit", do_mixhit);
	magic->name = "凌霄十三剑";
	magic->mp = 2500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  damage,dodge,lvl;
	}action[8] = {
		{"$N手中$w一振，化作一道白芒飞向$n！", 50, 0 , 0,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 100, 5 , 40,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 150, 10 , 80,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 200, 15 , 120,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 250, 20 , 160,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 300, 30 , 200,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 400, 40 , 240,},
		{"$N手中$w一振，化作一道白芒飞向$n！", 500, 50 , 255,},	//Learn Level Max:250.
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lingxiao_kuaijian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("dodge", (me->query("skill_pro/逍遥派/凌霄快剑/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/逍遥派/凌霄快剑/damage")+100) * action[level].damage/100);
	
			break;
		}
	}
	
	return & m_actions;
};


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/逍遥派/凌霄快剑/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/凌霄快剑/dodge"));
			if(me->query("skill_pro/逍遥派/凌霄快剑/dodge_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/凌霄快剑/dodge",1);
				me->set("skill_pro/逍遥派/凌霄快剑/dodge_point",1);
				tell_object(me,"\n$HIR你的凌霄快剑使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/逍遥派/凌霄快剑/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/凌霄快剑/damage"));
			if(me->query("skill_pro/逍遥派/凌霄快剑/damage_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/凌霄快剑/damage",1);
				me->set("skill_pro/逍遥派/凌霄快剑/damage_point",1);
				tell_object(me,"\n$HIR你的凌霄快剑威力更大了。\n");
			}
		}
	}
	return "";
}


int valid_enable(string usage) 
{ 
	return (usage == "sword") ;
}

int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 2500)
		return notify_fail("你的内力不够。");
	if (DIFFERSTR(me->querystr("family/master_id"), "qingyun"))
		return notify_fail("凌霄快剑只能向端木青云学习。");
	//if (me->query_skill("beiming_shengong", 1) < 130)
	//	return notify_fail("你的北冥神功火候太浅。");
	//if (me->query_skill("beiming_shengong", 1) >= 140)
	//	return notify_fail("你的北冥神功火候太深。");
	return 1;
}

int practice_skill(CChar * me)
{
	return notify_fail("凌霄快剑的真意在于迅快，只能在动手中提升！");
	// Disable Practice.
}

//perform 

static int do_mixhit(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("凌霄十三剑无法使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("凌霄十三剑无法使用。");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "lingxiao_kuaijian"))
		return notify_fail("必须配合凌宵剑法使用。");

	if (me->query_skill("beiming_shengong", 1) < 130)
		return notify_fail("你的北冥神功火候太浅。");
	if (me->query_skill("beiming_shengong", 1) >= 140)
		return notify_fail("你的北冥神功火候太深。");

	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	int i;

	i=me->query_skill("lingxiao_kuaijian",1);
	i=i/10;		// 250:25 pfm casts i/2 
	if (i<12)
	{
		return notify_fail("你的凌霄十三剑等级不够！");
	}

	if( me->query("mp") < i*125 )		// 飞一剑需要250mp.六剑需要1500mp,十三剑需要3250mp?ok...
		return notify_fail("你的真气不够你使出这个等级的凌霄十三剑！");

	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		me->add("mp",-i*125);
	else
		me->add("mp",-i*125*(100-me->query_temp("apply/sub_mp"))/100);

	snprintf(msg ,255,"$N长吸一口气，精华内敛，神气贯通，其身其心都融入至高境界，手中长剑微微晃动……"  );
	message_vision(msg, me);

	i = (32 - i);
	if(i < 1) i = 1;

	me->call_out(remove_effect, i, target->object_id(), (30-i));
		
	me->start_busy(3);

	return 1;
}

static void remove_effect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	CContainer * weapon;
	char msg[255];

	me->start_busy(1);

	if( !target || !me->is_fighting(target) )
		return ;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return ;

	if(! living(me))
		return ;

	snprintf(msg ,255,"$N一顿，只见剑光一闪，凌霄十三剑随心念而出！"  );
	message_vision(msg, me);

	int i = amount1 * 5 / 2;
	if (i>13)
		i=13;	// Max: 13.
	
	for(int n = 0; n < i; n++)
	{
		if(EQUALSTR(me->query_skill_mapped("sword"), "lingxiao_kuaijian"))
		{
			snprintf(msg ,255,"只见$N剑势如潮，叠涌而来！"  );
			message_vision(msg, me);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		else
			break;
	}	
		
	me->start_busy(i-2);
	
	return;	
}

SKILL_END;
