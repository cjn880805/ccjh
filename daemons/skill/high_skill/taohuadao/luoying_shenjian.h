
// luoying_shenjian.h 落英神剑
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSluoying_shenjian);

virtual void create()
{
	set_name( "落英神剑");
	set("valid_force", "bibo_shengong");

	set("diff",100);
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,parry,damage;
		char damage_type[5];
	}action[] = {
		{"$N使一招「落英缤纷」，身形向上飘起，手中$w虚虚实实幻出万点剑花纷纷扬扬撒向$n$l", 100, 5, 40, "刺伤",},
		{"$N舞动$w，一式「人面桃花」，左手向$n面门一晃，右手$w抖出几朵剑花挟着虎虎剑气刺向$n的$l", 140, -20, 50, "刺伤",},
		{"$N身形绕$n一转，手中$w望空一指，一式「急风骤雨」幻出满天剑影，向$n$l接连挥出数剑", 180, 10, 70, "割伤",},
		{"$N身形飘然而起，在半空中身子一旋，悠然一式「江城飞花」手中$w若有若无淡淡刺向$n的$l", 210,-10 , 120, "刺伤",},
		{"$N纵起丈余，一式「细云巧翻胸」头下脚上，一招「万花齐落」手中$w舞成一个光球罩向$n的$l", 240, 10, 120, "刺伤",},
		{"$N一声大喝使出「漫天花雨」，手中$w幻出漫天花瓣，迅若奔雷射向$n的$l", 280, 15, 140, "刺伤",},
		{"$N轻叹一声，手中$w怀中一抱，一时「落花无意」，$w锵然跃出倏的化作几点带露的桃花，飘然飞向$n的$l", 320, 0,140 , "刺伤",},
	};

	int level = 0;
	
	level = random(7);
	m_actions.set("action", action[level].action);
/*	m_actions.set("force", action[level].force);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
*/
	m_actions.set("force", (me->query("skill_pro/桃花岛/落英神剑/force")+100) * action[level].force/100);
	m_actions.set("parry", (me->query("skill_pro/桃花岛/落英神剑/parry")+100) *action[level].parry);
	m_actions.set("damage", (me->query("skill_pro/桃花岛/落英神剑/damage")+100) * action[level].damage/100);

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/桃花岛/落英神剑/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/落英神剑/force"));
			if(me->query("skill_pro/桃花岛/落英神剑/force_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/落英神剑/force",1);
				me->set("skill_pro/桃花岛/落英神剑/force_point",1);
				tell_object(me,"\n$HIR你的落英神剑配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/桃花岛/落英神剑/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/落英神剑/parry"));
			if(me->query("skill_pro/桃花岛/落英神剑/parry_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/落英神剑/parry",1);
				me->set("skill_pro/桃花岛/落英神剑/parry_point",1);
				tell_object(me,"\n$HIR你熟练的使用落英神剑，防守能力进一步加强了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/桃花岛/落英神剑/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/落英神剑/damage"));
			if(me->query("skill_pro/桃花岛/落英神剑/damage_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/落英神剑/damage",1);
				me->set("skill_pro/桃花岛/落英神剑/damage_point",1);
				tell_object(me,"\n$HIR你的落英神剑威力更大了。\n");
			}
		}
	}
	return "";
}


virtual int valid_learn(CChar * me)
{
	CContainer * ob;

    if(  me->query_skill("bibo_shengong",1) < 30)
        return notify_fail("你的碧波神功火候还不够。");

    if(  me->query("max_mp") < 100 )
        return notify_fail("你的内力不够，不能练落英神剑。");

	if (!(ob = me->query_weapon())
	||  DIFFERSTR(ob->querystr("skill_type"), "sword"))
		return notify_fail("你必须先找一把剑才能学习剑法。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * ob;

    if(  me->query("hp") < 30
    ||   me->query("mp") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习落英神剑。");

	if (!(ob = me->query_weapon())
	||  DIFFERSTR(ob->querystr("skill_type"), "sword"))
		return notify_fail("你必须先找一把剑才能习练剑法。");

    me->receive_damage("hp", 30);
	me->add("force", -5);
    tell_object(me,"你按著所学练了一遍落英神剑。", "practice");
	return 1;

}

SKILL_END;
