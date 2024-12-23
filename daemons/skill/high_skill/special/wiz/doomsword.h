// doomsword.h 连城剑法
//code by Teapot
//date : 2001-02-07

SKILL_BEGIN(CSdoomsword);

virtual void create()
{
	set_name( "连城剑法");

	Magic_t * magic;

	magic = add_magic("zhuang", do_zhuang);
	magic->name = "天下八剑";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,lvl;		
	}action[5] = {
		{"$N使出连城剑法中绝杀一式，手中长剑一抖，笔直刺出！",500 , 5, 0},
		{"$N手一抖，一招「雪雾连城」幻成一片剑影散出！", 500, 10, 10},
		{"$N剑锋忽转，一招「闪刹连城」闪电般劈出！",500 , 15, 20,},
		{"$N身影晃动，剑影忽左忽右，一招「空乱连城」从中路直劈而过！", 500, 20, 30},
		{"$N双脚点地，剑刃倒转，剑柄磕出，正是连城剑法不传之密「谙寂灭」", 500,25 , 40},
	};

		struct {
		char action[255];
		int  force,dodge,lvl;		
	}action2[8] = {
		{"$HIG$N双手握起$w，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺！", 300, -25, 40},
		{"$HIB$N使出玄铁重剑式中「奔潮诀」，内力磅礴而出，辅以$w剑气，如大潮滔天而至扑向$n！", 300, -25, 40},
		{"$HIR$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n！", 300, -25, 40},
		{"$HIW$N举剑画弧，默潜独孤九剑之「破剑式」，绵绵剑意，漫天铺地袭向$n！", 300, -25, 40},
		{"$HIC$N使出「五韵齐出」，清音长啸，剑掌齐出，攻向$n！", 300, -25, 40},
		{"$CYN$N使出全真派绝技「一剑化三清」，身法陡然加快,手握剑柄晃成三条白龙刺向$n！", 300, -25, 40},
		{"$HIY$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快，连刺三剑！", 300, -25, 40},
		{"$YEL$N手腕一抖，一式「势合形离」，泛出数朵剑花连续刺向$n！", 300, -25, 40},
	};

	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("doomsword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}

	int j;
	j=me->query_temp("teapot/perform_tianxiabajian");
	if (j)
	{
			m_actions.set("action", action2[j-1].action);
			m_actions.set("force", action2[j-1].force);
			m_actions.set("dodge", action2[j-1].dodge);
			me->add_temp("teapot/perform_tianxiabajian",1);
	}


	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	return 0;
	// Disable Learn.
}

virtual int practice_skill(CChar * me)
{
	return 0;
	// Disable Practice.
}

//perform 

static int do_zhuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("天下八剑无法使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("天下八剑无法使用。");
	
	if( me->query("mp") < 5 )
		return notify_fail("你的真气不够！");
	
	snprintf(msg ,255,"\n$WHT$N神气贯通，将连城剑法绝技「天下八剑」一气呵成！"  );
	message_vision(msg, me);

	me->set_temp("teapot/perform_tianxiabajian",1);

	snprintf(msg ,255,"\n$HIG玉女剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIB玄铁剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIR辟邪剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIW独孤剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIC五韵剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$CYN全真剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIY达摩剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$YEL玉箫剑！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	
	me->delete_temp("teapot/perform_tianxiabajian");
	
	me->add("mp", -5);
	me->start_busy(random(3));	// 8 Hits and busy r.d.3,the best multi-strike perform.
	
	return 1;
	
}

SKILL_END;
