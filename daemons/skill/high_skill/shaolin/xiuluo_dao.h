SKILL_BEGIN(CSxiuluo_dao);

virtual void create()
{
	set_name( "���޵�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[10] = {
		{"$N�ص����գ�һ�С�������ӥ�����������¶��ϻ��˸��뻡����$n��$l��ȥ",
			120, -10, 5, 15, 0,},
		{ "$N�����������⣬һ�С�Ͷ�������������$w��ֱ����$n��$l",
		130, -10, 10, 20, 12,},
		{ "$Nһ�С��ͷл�졹��$w�ƾ�������ˢ��һ�����϶�����$n����",
		140, -5, 5, 25, 18,},
		{ "$N���ַ�ִ������һ�С��۹ǳ��衹����һ����$wֱ��$n�ľ���նȥ",
		160, 5, 5, 30, 24,},
		{"$Nһ�С�����ǧ�ơ����������⻯����㷱�ǣ���$n��$l��ȥ",
		180, 10, 5, 35, 30,},
		{ "$N˫�ֺ�ִ$w��һ�С����۲�ʩ����š��ת������ֱ����$n��˫��",
		210, 15, 15, 40, 36,},
		{ "$Nһ�С���Ƥ�龭��������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
		240, 15, 15, 50, 42,},
		{ "$N��ת�����׼�Լ���һ�С����ľ�־����ȫ��һ��������$w��$n����նȥ",
		280, 20, 10, 60, 48,},
		{ "$Nһ�С������𡹣�$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
		320, 10, 20, 75, 54,},
		{"$N����ƽָ��һ�С���Ѫ���ء���һƬƬ�йǵ�����쫷�����$n��ȫ��",
		370, 5, 25, 90, 60,},
	};

	int level = me->query_skill("xiuluo_dao", 1);
	for(int i = 10; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
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

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("����������������޵���");
	me->receive_damage("hp", 35);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");
	return 1;
}

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry";  }
virtual int valid_combine(string combo) {return combo=="damo_jian";  }


SKILL_END;