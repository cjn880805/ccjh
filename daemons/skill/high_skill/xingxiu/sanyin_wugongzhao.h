//sanyin_wugongzhao.h 三阴蜈蚣抓
SKILL_BEGIN(CSsanyin_wugongzhao);

virtual void create()
{
	set_name( "三阴蜈蚣抓");
	set("valid_force", "huagong_dafa");
}

virtual int valid_enable(string usage) { return usage=="claw" ||  usage=="parry";}
virtual int valid_combine(string combo) { return combo=="xingxiu_duzhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
        return notify_fail("练三阴蜈蚣爪必须空手。");
    if (me->query("max_mp") < 200)
        return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。");

	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 150) 
	{
		victim->apply_condition("xx_poison", random(60) + 1 +
			victim->query("condition/xx_poison"));
    }
	return "";
}
virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[4] = {
		{"$N爪现青白，骨结隆起，自上而下撕扯$n的$l",
			120, 10, 70, 10,},
		{"$N双手忽隐忽现，爪爪鬼魅般抓向$n的$l",
			150, 10, 85, 10,},
		{"$N身形围$n一转，爪影纵横毫不留情对着$n的$l抓下",
			180, 10, 85, 10,},
		{"$N一声怪叫，一爪横出直击$n的天灵盖",
		280, 10, 100, 100,},
	};

	int level = me->query_skill("sanyin_wugongzhao",1);

	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
	
			break;		
		}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练三阴蜈蚣爪。");
	
	me->receive_damage("hp", 30);
    me->add("mp", -10);

	return 1;
}

SKILL_END;