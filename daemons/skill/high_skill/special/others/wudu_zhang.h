//�߼�����
//wudu_zhang �嶾��

SKILL_BEGIN(CSwudu_zhang);

virtual void create()
{
	set_name( "�嶾��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N˫��һ�������ƴ��ŵ��������⣬ֱ��$n��ȥ", 180, 5, 20, 50, 0,},
		{"$N������Σ�����ֱ�������綾��һ��ֱ��$n����ǰ", 220, 10, 15, 60, 10,},
		{"$N˫�Ʒ��ɣ�������ã��һ�ɰ���������������$n��ȫ��", 260, 15, 20, 70, 20,},
		{"$N����һ�֣�������Ы���������ߣ�ͬʱ��$n����ȥ", 300, 20, 30, 80, 30,},
		{"$NĬ��������˫�ƺ�Ȼ��ڣ�����һ������ֻ��$n��ȫ��", 340, 25, 20, 100, 40,},
	};

	int level = me->query_skill("wudu_zhang", 1);

	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("��������������嶾�ơ�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("���嶾�Ʊ�����֡�");
	if (me->query_skill("wudu_xinfa", 1) < 20)
		return notify_fail("����嶾�ķ���򲻹����޷�ѧ�嶾�ơ�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷����嶾�ơ�");
	return 1;
}

virtual int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("wudu_zhang")) > 10 )
		victim->apply_condition("wudu_poison",
								random(me->query_skill("wudu_zhang")/10 + 1) + 1 + 
								victim->query("condition/wudu_poison"));
	return 0;
}

SKILL_END;

//wudu-xinfa �嶾�ķ�ȱ
//wudu_poison �嶾�ж�

