// duanyun_fu.c 断云斧

SKILL_BEGIN(CSduanyun_fu);

virtual void create()
{
	set_name( "断云斧");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[8] = {
		{"$N蓦地腾空跃起，双手紧握$w，对准$n的头顶，自上而下地砍了下去，只在半空中留下一团巨大的黑影",
			300, 50, 0,},
		{"$N突然发一声喊，冲前两步，手中$w由下而上反撩$n下三路，$n见到一道淡黄色的气影逼向自己，情知不妙，急忙招架",
		325, 45, 10,},
		{"$N忽然虎吼一声，闪身斜向左前方冲出一步，身体微晃，手中$w在空中划出一道淡影，急速横扫$n的右肩，气势迫人",
		350, 40, 20,},
		{"$N突然抽身向右滚倒，随即跳起，就在跳起的一瞬间，已单臂握着$w砸向$n的左肋，出手既快且狠",
		390, 35, 30,},
		{"$N双手横举$w，平扫$n前胸，招式未使老就已打住猝然变招，斧尖直撞$n的小腹",
		430, 40, 42,},
		{"$N不急不缓地转身微蹲，$n见$N露出破绽，急忙抢攻，却突然发现$N的身体已转过来，手中$w正迅猛地扫向自己的下盘",
		480, 30, 55,},
		{"$N身形微动，就在同一时间自上中下左右砍出五斧，$n见五把$w从不同的方位砍向自己，一时间竟不知该如何招架",
		540, 25, 68,},
		{"$N前脚猛地往地上一顿，大地也微微一震，接着举起斧头在头顶急转数圈，$w就隐含风云之声平直而沉稳地袭向$n，$n无论向何处闪躲，总看见斧尖离自己不到一尺，不由大惊失色",
		600, 65, 80,},
	};
	
	int level = me->query_skill("duanyun_fu", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
		
		return & m_actions;
};

virtual int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 150)
		return notify_fail("你的内力不够。");
	
	if (me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。");
	
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "axe"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了断云斧。");
	
	me->receive_damage("hp", 25);
	return 1;
}

SKILL_END;

