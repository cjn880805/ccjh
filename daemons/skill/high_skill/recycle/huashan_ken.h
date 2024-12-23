// huashan_ken.h 华山拳法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_ken);

virtual void create()
{
	set("name", "华山拳法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「云里乾坤」左拳击出，不等招式使老，右拳已从左拳之底穿出，对准$n的$l「呼」地一拳", -40, 40,0,"瘀伤",},
		{"$N左拳突然张开，拳开变掌，直击化为横扫，一招「雾里看花」便往$n的$l招呼过去",  -30, 30,10,"瘀伤",},
		{"$N两手虎口相对，往内一圈，一招「金鼓齐鸣」往$n的$l击出", -30, 30,20,"瘀伤",},
		{"$N步履一沉，左拳虚晃一招，右拳使出「梅花弄影」击向$n$l", -30, 30,30,"瘀伤",},
	};
 	
	int level = 0;
	
	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_ken", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if( me->query_weapon() )
	   return notify_fail("练华山拳法必须空手。");
    return 1;

}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30 )
   return notify_fail("你的体力不够了，休息一下再练吧。");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;
