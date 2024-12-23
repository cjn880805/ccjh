//wudang-jian.c 武当剑法
SKILL_BEGIN(CSwudang_jian);

virtual void create()
{
	set_name( "武当剑法");
	set("valid_force", "taiji_shengong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[] = {
		{"$N身体左转，左手剑指，两腿屈膝，右前臂内旋，剑尖前端一寸处短促抖腕发力，一招「飞燕入林」，手中$w轻轻颤动，一剑自上而下扎向$n的$l", 120, 20, 25, 0,},
		{"$N身形不动，右前臂外旋，剑刃上崩，立马左腿左弓步，一招「青龙吐水」，手中$w向前下反刺，一剑指向$n的$l", 120, 20, 10, 0,},
		{"$N左脚向前一步，蹬地跳起，身体腾空疾速左转，右手$w先向前刺，随转体变向，使出一式「凤凰挚窝」，剑光如匹练般泄向$n的$l", 140, 15, 25, 0,},
		{"$N力贯鞭梢，一招「蟾蜍出洞」，手中$w忽左忽右，直劈向$n胸口", 150, 15, 35, 0,},
		{"$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式「玉女穿梭」，剑锋往来运转如梭，连绵不绝刺向$n的$l", 130, 25, 25, 0,},
		{"$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出一式「仙人指路」刺向$n的$l", 120, 25, 25, 0,},
		{"$N左撤步，抱剑当胸，挥剑做圆环形，正反搅动，右手$w一式「怀中抱月」，剑意圆润，刺向$n的$l", 110, 15, 25, 0,},
		{"$N侧身退步，左手剑指划转，腰部一扭，上体后仰，右手$w一记「反身朝阳」自下上撩指向$n的$l", 150, 35, 45, 0,},
	};

	int level = random(8);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	
	if (me->query("mp") < 10)
		return notify_fail("你的内力不够。");
	if (me->query_skill("force", 1) < 20)
		return notify_fail("你的内功火候太浅。");
	if (me->query_skill("unarmed", 1) < 20)
		return notify_fail("你的基本拳脚火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 20)
		return notify_fail("你的体力不够练武当剑法。");
	me->receive_damage("hp", 10);
	return 1;
}

SKILL_END;
