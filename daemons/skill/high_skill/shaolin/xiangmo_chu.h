SKILL_BEGIN(CSxiangmo_chu);

virtual void create()
{
	set_name( "��ս�ħ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int dodge, parry, lvl, damage;
	}action[8] = {
		{ "$N�߾�����$w��ʹ��һ�С������������ֱ��$n��$l  ",
			-5, 10, 0, 30,},
		{"$Nʹ������շ�ħ���������趯$w��һ����$w��ɨ$n������  ",
		5, 0, 8, 40,},
		{ "$N�������棬ʹ��һʽ�������������˫����$W��һ��ֱ��$n��$l  ",
		10, 5, 16, 50,},
		{"$Nʹ��һ�С���Ȥ��������˫�־ٹ�����$n���ɲ�  ",
		0, 10, 24, 60,},
		{ "$N�趯����$w��ʹ�����������ޡ�����ʱ��ס$n��ȫ��  ",
        10, 10, 32, 80,},
		{"$Nʹ��һ�С�����Ѫ������ȫ�����ض��ɣ�һ��ֱ��$n��$l  ",
		15, 5, 40, 100,},
		{ "$Nʹ��һʽ��������ħ�����Թ�֧�أ�˫��ɴ�$n������  ",
		20, 0, 48, 150,},
		{ "$N�������ƣ�ʹ������ħ��������������������$w��ɨ$n��$l  ",
        20, 15, 56, 180,},
	};

	int level = me->query_skill("xiangmo_chu", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
		
			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("������������������˽�ս�ħ�ơ�");
	me->receive_damage("hp", 30);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "staff" || usage == "parry";  }

SKILL_END;