//duanhun_qiang.h 断魂枪

SKILL_BEGIN(CSduanhun_qiang);

virtual void create()
{
	set_name( "断魂枪法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[]={
		{"$N使一招「周身皆梦」，手中$w一抖，化出无数枪头，直刺$n的$l。",100,-100,200,"刺伤"},
		{"$N使出断魂枪中的「执梦为真」，手中$w晃动，虚点数枪，突然自影中发出一枪，刺向$n的$l。",140,-120,220,"刺伤"},
		{"$N一招「诸皆成梦」，向前猛窜，手中$w反背一枪，直扎$n的$l。",180,-130,180,"刺伤"},
		{"$N手中$w一式「梦中知梦」，手中$w枪头乱抖，铺天盖地杀来，枪枪不离$n的$l。",220,-120,160,"刺伤"},
        {"$N的$w虚点，蓦地进步跟身，一招「观物达观」刺向$n的$l。",300,-110,150,"刺伤"},
       	{"$N手中$w一递，枪身竟如残月般弯转，一招「一念回光」反手对准$n$l一枪刺去。",330,-100,140,"刺伤"},
	};
		
	int level = random(6);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$n使出一招「过眼烟云」，手中的$W荡开了$N的$w。"},
		{"$n使出「梦中说梦」，将$N的$w封于丈外。"},
		{"$n使出一招「踏遍天涯」，手中的$W化做漫天残照，荡开了$N的$w。"},
		{"$n手中的$l一抖，一招「久历歧途」，向$N拿$w的手腕刺去。"},
		{"$n将手中的$W舞得密不透风，一招「荆榛丛中」封住了$N的攻势。"},
		{"$n反手一招「云浮华相」，整个人消失在一团剑光之中。"},
		{"$n使出一招「光万境闲」，$W直刺$N的双手。"},
		{"$n将手中的$W一抖，一招「天涯空驰」，迫得$N连连后退。"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(4)+4];
}

virtual int valid_enable(string usage) 
{ 
	return usage=="club" ||  usage=="parry"; 
}


virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("你的内力不够。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练断魂枪法。");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;