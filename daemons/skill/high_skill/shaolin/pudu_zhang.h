SKILL_BEGIN(CSpudu_zhang);

virtual void create()
{
	set_name( "�ն��ȷ�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$Nʹһ�С���ţת�ǡ�������$w���¶��ϣ������ޱȵ���$n��С����ȥ��",
			180, -10, 15, 0,},
		{"$N�첽�����һ�С�Ұ��׷�硹������ƽ��$w�����������ȶˣ�����$n���ؿڡ�",
		200, -10, 20, 9,},
		{"$N�߾�$w��һ�С��ͻ���������ȫ��Ծ������$w§ͷ�Ƕ�����$n��ȥ��",
		230, -5, 30, 18,},
		{"$Nһ�С�ʨ��ҡͷ����˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���һ�����硣",
		270, -10, 35, 27,},
		{"$N���$w��һ�С�������β�����ȶ˻���������ԲȦ�����ͳ��أ���$n�������С�",
		320, -15, 40, 36,},
		{"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С�������������Ӱ��$n��������",
		380, 5, 55, 45,},
		{"$N˫�ֺ�ʮ������һ�С���ɮ�в�����$w������ɳ���������$nײȥ��",
		450, -5, 55, 53,},
		{"$Nһ�С��Ⱥ��նɡ���$w�������������Ծ����ֱ��$n���ؿڴ��롣",
		530, -5, 60, 60,},
	};

	int level = me->query_skill("pudu_zhang", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
		
			break;
		}
	
	return & m_actions;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("�ն��ȷ����������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������ն��ȷ���");
	me->receive_damage("hp", 30);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");
	return 1;
}

virtual int valid_enable(string usage) {return (usage == "staff") || (usage == "parry"); }

SKILL_END;