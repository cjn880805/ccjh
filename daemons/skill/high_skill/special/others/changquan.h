//changquan.h  长拳

//coded by Fisho
//data: 2000-11-1

SKILL_BEGIN(CSChangQuan);

virtual void create()
{
	set_name( "长拳");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force;
			char damage_type[5];
	}action[]={
		{"只见$N身形一矮，大喝声中一个「冲天炮」对准$n的鼻子呼！地砸了过去", 5, 5, 90, "砸伤",},
		{"$N左手一分，右拳运气，一招「拔草寻蛇」便往$n的$l招呼过去", 5, 5, 60, "瘀伤",},
		{"$N右拳在$n面门一晃，左掌使了个「叶底偷桃」往$n的$l狠命一抓", 5, 5, 60, "抓伤",},
		{"$N步履一沉，左拳拉开，右拳带风，一招「黑虎掏心」势不可挡地击向$n$l", 5, 5, 80, "瘀伤",},
		{"只见$N拉开架式，一招「双风贯耳」使得虎虎有风。底下却飞起一脚踢向$n$l", 5, 5, 70, "瘀伤",},
		{"$N打得兴起，大喝一声：看我这招「龙虎相交」！\n左手往$n身后一抄，右拳便往$n面门砸了过去", 5, 5, 120, "砸伤",},
		{"$N拉开后弓步，双掌使了个「如封似闭」往$n的$l一推", 5, 5, 50, "瘀伤",},
		{"只见$N运足气力，一连三拳击向$n$l，力道一拳高过一拳！\n这一招的名字还相当高雅，叫作「阳关三叠」",5, 5, 80,  "瘀伤",},
		{"$N往后一纵，就势使了个「老树盘根」，右腿扫向$n的$l", 5, 5, 50, "砸伤",},
		{"$N一个转身，左掌护胸，右掌反手使了个「独劈华山」往$n当头一劈", 5, 5, 90, "砸伤",},
		{"$N飞身跃起，半空中一脚踢向$n面门，却是个虚招。\n说时迟那时快，只见$N一个倒翻，双掌已到了$n的$l", 5, 5, 100, "瘀伤",},
	};
		
	int level = random(11);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
		
	return & m_actions;
}

int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("练长拳必须空手。");

    return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

int valid_combine(string combo) 
{ return combo=="tangshoudao"; }        


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

