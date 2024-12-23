//lovesteps.h 醉卧花阴
//code by Teapot
//date : 2001-03-10

SKILL_BEGIN(CSlovesteps);

virtual void create()
{
	set_name( "醉卧花阴");
}

virtual CMapping * query_action(CChar * me)
{
	static struct {
		char action[255];
		int dodge;
	}action[6] = {
		{"$n脸上突然浮现出一片哀怜，看得$N不忍再下手。", 10,},
		{"$n低头轻叹一声，不闪不避，$N一愣，默默停手。", 20,},
		{"$n慢慢向$N怀中倒去，$N只能停手来接。", 30,},
		{"$n道：好，好，你……你欺负我！，说话间眼圈已经红了，$N一愣，停手不攻。", 40,},
		{"$n轻轻吟道：一夜夫妻百日恩，百夜夫妻海样深……$N听得心中一阵伤感，不由停下招式。", 50,},
		{"$n什么也不说，两道清澈如水的目光看着$N，$N心中千回百转，念起$n过去的好来。", 50,},
	};

	int level;
	level = random(6);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", 1000);

	return & m_actions;
}

virtual int valid_enable(string usage) { return usage == "dodge" ||usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual const char * query_dodge_msg(CChar * me)
{
	query_action(me);
	return m_actions.querystr("action");
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练醉卧花阴。");
	me->receive_damage("hp", 0);
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;