// mingwang_jian.c ������ ����������


SKILL_BEGIN(CSmingwang_jian);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, lvl, damage;
	}action[] = {
		{"$NŭĿԲ����ʹ��һ�С�������������$wһ����ֱ��$n��$l ", 100, -10, 0, 30,},
		{"$Nʹ��һʽ�����ֳ�����������һ������â����$n��$l", 140, 5, 8, 30,},
		{"$Nʹ��һ�С�ɽ����������Ծ���գ�$w��ɽ��������$n��$l", 180, -10, 16, 40,},
		{"$Nʹ����ǧ��ת������$w�����ĳ�һ�㣬��Ȼһ������$n��$l", 220, 10, 24, 48,},
		{"$Nʹ��һ�С���ħ�衹��ȫ��������$w�У�����ֱָ$n��$l", 250, 10, 32, 54,},

		{"$N���������ʹ��һʽ�����衹��һ���������Ӱ����$n��$lɨȥ", 280, 15, 40, 60,},
		{"$Nʹ��һ�С����ڡ�������$w������������$n��$l", 300, 20, 48, 66,},
		{"$N����һԾ���Ӹ�����ʹ�����������졹����ʱ�����������$n��$l", 320, 25, 80, 80,},
	};
	
	int level = me->query_skill("mingwang_jian", 1);
	
	CContainer * weapon;
	weapon = me->query_weapon();
	char msg[255];
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			if (weapon->query("mingwang_jian") && me->query("mp")>20)
			{
				m_actions.set("force", action[level].force*2);
				me->add("mp",-20);
				snprintf(msg,255,"$HIW %s $COM",action[level].action);
				m_actions.set("action", msg);
			}
			else
			{
				m_actions.set("force", action[level].force);
			}
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("force", 1) <= 30 )
		return notify_fail("��Ļ����ڹ���򲻹���");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("���������������������������");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;




