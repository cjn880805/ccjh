SKILL_BEGIN(CSwuchang_zhang);

virtual void create()
{
	set_name( "�޳��ȷ�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[12] = {
		{"$N΢һ����һ�С�ӹ�����š���$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
			100, -10, 5, 15, 0,},
		{"$Nһ�С�����Ƿǡ���������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
		110, -10, 10, 15, 7,},
		{"$Nһ�С����񲻰���������$wƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
		120, -5, 5, 20, 14,},
		{"$Nһ�С�������ɫ��������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$1",
		130, -5, 5, 20, 20,},
		{"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ�С��ľ��������������к��ų���$n",
		140, -15, 15, 30, 25,},
		{"$Nһ�С���ʬ���⡹��ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
		150, 5, -15, 30, 30,},
		{"$N�����ɫ��һ�С���������������$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
		300, -5, 20, 40, 35,},
		{"$Nһ�С��������ġ������⽫$wˤ����ϣ���$n������һ�Ź��𣬻���$n��$1",
		350, -5, 25, 40, 40,},
		{"$N����װ����һ�С���;û·����һ������������$w��������������$n���ɲ�",
		400, -5, 25, 50, 45,},
		{"$Nһ�С�����ľ�������������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е�����$n��$1",
		450, -5, 25, 50, 50,},
		{"$N�߾�$w��һ�С��˹���;������������Ȱ�Ʈ������׼$n�������һ�ȴ���",
		500, -5, 25, 60, 55,},
		{"$Nһ�С���������������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
		550, -5, 25, 60, 60,},
	};

	int level = me->query_skill("wuchang_zhang", 1);
	for(int i = 12; i > 0; i--)
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

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("�޳��ȱ��������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������޳��ȷ���");
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

virtual int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

SKILL_END;