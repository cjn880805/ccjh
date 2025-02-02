//juemen_gun.h 绝门棍
//LANWOOD 2000-01-04

SKILL_BEGIN(CSjuemen_gun);

virtual void create()
{
	set_name( "绝门棍");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[5] = {
		{"$N斜里冲前一步，身法诡异，手中$w横扫$n的$l",
			350, 60,},
		{"$N忽然直身飞入半空，很久也不见人影，$n正搜寻间，$N已飞身扑下，$w攻向$n的$l",
		400, 55,},
		{ "$N原地一个后滚翻，却在落地的一刹那，身体向$n平飞过去，手中$w指向$n的$l",
		350, 70,},
		{"$N突然一个急转身，$w横扫一圈后挟着猛烈的劲道打向$n的$l",    
		450, 85,},
		{ "$N向前扑出，顺势一滚，接着翻身跳起，手里$w斜向上击向$n的$l",
		400, 75,},
	};
 
  	int level = random(5);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="staff" || usage=="parry"|| usage=="dodge"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练绝门棍。");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if (me->query("mp") < 20)
		return notify_fail("你的内力不够练绝门棍。");
    me->receive_damage("hp", 20);
    return 1;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[5][80]={	
		{"$n右脚轻轻一点跃开躲过了$N的攻击。",},
		{"$n向旁边扑出，顺势一滚，闪到一边。",},
		{"$n斜里冲前一步，身法诡异，$N这一招落到空处。",},
		{"$n忽然直身飞入半空，很久也不见人影，半响后竟闪到了$N的背后。",},
		{"$n突然一个急转身，$N的这一招滑到了一边。",},
	};

	return dodge_msg[random(5)];
}

SKILL_END;

