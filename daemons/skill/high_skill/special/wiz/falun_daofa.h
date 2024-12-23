// falun_daofa.h 如意法轮连环八刀
//code by Teapot
//date : 2001-02-06

SKILL_BEGIN(CSfalun_daofa);

virtual void create()
{
	set_name( "如意法轮连环八刀");

	Magic_t * magic;

	magic = add_magic("zhuang", do_zhuang);
	magic->name = "法轮常转";
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
		char damage_type[5];
	}action[] = {
		{"$N使出法轮八式中的起手式「法轮旋转式」，手中的$w划出一溜光芒斩向$n的$l",500 , 5, 0,"割伤",},
		{"$N手一抖，一招「法轮翻飞式」手中的$w幻成一片刀花，散向$n的$l", 300, 10, 10,"割伤",},
		{"$N刀锋忽转，手中的$w一招「法轮破天式」，闪电般劈向$n的$l",320 , 15, 20,"瘀伤",},
		{"$N身影晃动，刀锋忽左忽右，一招「法轮无边式」，手中的$w，从中路突然砍至$n的$l", 300, 20, 30,"瘀伤",},
		{"$N的双脚点地，刀背贴身，一招「法轮乾坤式」全身转出一团刀光滚向$n", 300,25 , 40,"瘀伤",},
		{"$N刀刃向上，一招「法轮回天式」，从一个$n意想不到的角度撩向$n的$l", 360, 0, 50,"瘀伤",},
		{"$N你手中的$w左右横划，一招「法轮独尊式」，来来回回地狂扫向$n的$l", 420, 35, 60,"瘀伤",},
		{"$N使出如意天魔连环八式中的收手式「万法归宗式」，手中的$w迅捷无比地砍向$n的$l", 540, 40, 80,"瘀伤",},
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("falun_daofa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "blade") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 500)
		return notify_fail("你的内力不够。");
	if (me->query_skill("falun_gong", 1) < 20)
		return notify_fail("你还没有领悟法轮大法的精髓。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练如意法轮连环八刀。");
	me->receive_damage("hp", 30);
	return 1;
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
		return notify_fail("「法轮常转连环八式」只能在战斗中使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("「法轮常转连环八式」必须用刀！");
	
	if( me->query("mp") < 500 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("blade") < 144 ||
		DIFFERSTR( me->query_skill_mapped("blade") , "falun_daofa"))
		return notify_fail("你的如意法轮连环八刀还不到家，无法使用法轮常转连环八式！");

	
	snprintf(msg ,255,"$N神气贯通，将法轮常转连环八式一气呵成！"  );
	message_vision(msg, me);
	
	snprintf(msg ,255,"魔转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"身转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"意转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"心转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"神转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"刀转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"法轮转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"天地转！"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	
	
	me->add("mp", -500);
	me->start_busy(random(6));	// 8 Hits and busy r.d.6,the best multi-strike perform.
	
	return 1;
	
}

SKILL_END;
