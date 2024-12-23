//tangshoudao.h  唐手道

//coded by 55
//data: 2000-3-28

SKILL_BEGIN(CStangshoudao);

void create()
{
	set_name( "唐手道");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force;
			char damage_type[5];
	}action[]={
		{"只见$N身形一矮，大喝一声，一记正拳中规中矩地向$n的鼻子打了过去", 5, 5, 90, "砸伤",},
		{"$N上前一步，右膝提起，猛然撞出，右脚顺势扫向$n的头部。", 5, 5, 60, "瘀伤",},
		{"$N右脚往$n面门一踢，顺势高高举起落下，脚跟猛力砸向$n的面门", 5, 5, 60, "抓伤",},
		{"$N上身回转，左脚踩地旋转，右脚回扫，一招回旋踢势不可挡地击向$n", 5, 5, 80, "瘀伤",},
		{"只见$N身形一沉，上前一招「一本背负」，假装将$n一推，紧接却是一拉，矮身背负，企图将$n摔倒", 5, 5, 70, "瘀伤",},
		{"$N大喝一声：看我的飞踢！\n高高跳起打出一拳，接着一脚向$n面门踩了过去", 5, 5, 120, "砸伤",},
		{"$N上前一步靠近$n，突然间飞身跃起，半空回脚扫向$n后脑", 5, 5, 50, "瘀伤",},
		{"只见$N运足气力，一连三拳击向$n$l，力道一拳高过一拳！\n这一招的名字还相当长，叫作「走马连环拳」",5, 5, 80,  "瘀伤",},
		{"$N抓住$n的右手，上前一步，五指成啄打向$n的眼睛", 5, 5, 50, "砸伤",},
		{"$N一个转身，左掌护胸，右手手刀往$n当头一劈", 5, 5, 90, "砸伤",},
		{"$N飞身跃起，一脚踢向$n面门，却是个虚招。\n说时迟那时快，只见$N半空中一个转身，另一脚已到了$n的面前", 5, 5, 100, "瘀伤",},
	};
		
	int level = random(11);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
		
	return & m_actions;
}


virtual int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("练唐手道必须空手。");

    return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" ||  usage=="unarmed" ||usage=="parry";}
virtual int valid_combine(string combo) { return combo=="changquan"; }

int practice_skill(CChar * me)
{
	if( me->query("hp") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。");
   
	if( me->query("mp") < 10 )
		return notify_fail("你的内力不够了。");

	me->receive_damage("hp", 30);
	me->add("mp", -10);

	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

