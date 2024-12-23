// pixie_sword.h 辟邪剑法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSpixie_sword);

virtual void create()
{
	set_name( "辟邪剑法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「群邪辟易」，手中$w圈起，倏地刺出，银星点点，剑尖直向$n的$l刺去", 50,100 , 0,"刺伤",},
		{"$N一招「钟馗抉目」，剑随身转，围着$n身围疾刺，剑光霍霍罩向$n的$l", 70, 150, 1,"刺伤",},
		{"$N舞动$w，一招「花开见佛」挟著无数剑光刺向$n的$l", 40, 100, 2,"刺伤",},
		{"$N手中$w一声清啸，祭出「流星赶月」剑锋闪烁不定，银光飞舞，猛地里一剑挺出，直刺$n$l", 30, 100, 3,"刺伤",},
		{"$N手中$w剑光暴长，一招「飞燕穿柳」往$n$l刺去", 60, 100, 4,"刺伤",},
		{"$N手中$w化成一道光弧，直指$n$l，一招「江上弄笛」发出虎哮龙吟刺去", 10, 100, 5,"刺伤",},
	};
  	
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("pixie_sword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
   CContainer * ob;

    if (  EQUALSTR(me->querystr("gender"), "女性") )
        return notify_fail("女子不能学辟邪剑法.");

    if(  me->query("max_mp") < 50 )
        return notify_fail("你的内力不够，没有办法练辟邪剑法。");

    if( !(ob = me->query_weapon())
      ||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
          return notify_fail("你必须先找一把剑才能练剑法。");

    return 1;
}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30
    ||   me->query("mp") < 5 )
       return notify_fail("你的内力或气不够，没有办法练习辟邪剑法！");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"你按著所学练了一遍辟邪剑法。", "practice");
    return 1;
}

virtual void skill_improved(CChar * me)
{
	int lvl = me->query_skill("pixie_sword", 1);

	if(lvl > 10)
	{
		if( lvl % 10 == 0 )
		{
			tell_object(me,"你突然觉得一股阴气冲上心头，只觉得想杀人...." );
			me->add("repute", - 50);
		} 
		else
			me->add("repute", -5);
	}
}

SKILL_END;
