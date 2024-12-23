SKILL_BEGIN(CSshaolin_shenfa);

void create()
{
	set_name("少林身法");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int dodge;
	}action[8] = {
		{"$n一式「一苇渡江」，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。", 0,},
		{"$n一式「雨燕掠波」，双臂前伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。", 0,},
		{"$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。", 0,},
		{"$n一式「风驰电掣」，双脚点地，全身一道闪电，急速绕着$N飞奔。", 0,},
		{"$n一式「孤骛落日」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。", 5,},
		{"$n一式「鸿雁双飞」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。", 5,},
		{"$n一式「苍龙出水」，双脚点地，全身化为一道白影，急速绕着$N打了几转。", 10,},
		{"$n一式「稚凤归巢」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。", 15},
	};

	int level = me->query_skill("shaolin_shenfa", 1);

	int zhaoshu = 8;
	if (level < 80 )
		zhaoshu--;

	if (level < 60)
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;
       
	if (random(me->query_skill("dodge")) > 100 &&
            me->query_skill("force") > 90 &&
            me->query("mp") > 500) 
	{
        me->add("mp",-5);

		m_actions.set("action","$YEL$n陡然使出「少林身法」之绝技「分身化影」，身形犹如鬼魅消失得无影无踪!$COM");
        m_actions.set("dodge", 300);
		return &m_actions;
	}

	level = random(zhaoshu);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);

	return & m_actions;
}

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

int valid_learn(CChar * me)
{
	return 1;
}

int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练少林身法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;