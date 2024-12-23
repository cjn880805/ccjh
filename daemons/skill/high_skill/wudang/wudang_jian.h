//wudang-jian.c �䵱����
SKILL_BEGIN(CSwudang_jian);

virtual void create()
{
	set_name( "�䵱����");
	set("valid_force", "taiji_shengong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[] = {
		{"$N������ת�����ֽ�ָ��������ϥ����ǰ������������ǰ��һ�紦�̴ٶ�������һ�С��������֡�������$w���������һ�����϶�������$n��$l", 120, 20, 25, 0,},
		{"$N���β�������ǰ�������������ϱ������������󹭲���һ�С�������ˮ��������$w��ǰ�·��̣�һ��ָ��$n��$l", 120, 20, 10, 0,},
		{"$N�����ǰһ�����ŵ����������ڿռ�����ת������$w����ǰ�̣���ת�����ʹ��һʽ�����ֿ�ѡ���������ƥ����й��$n��$l", 140, 15, 25, 0,},
		{"$N������ң�һ�С���ܳ�����������$w������ң�ֱ����$n�ؿ�", 150, 15, 35, 0,},
		{"$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ����Ů���󡹣�����������ת�������಻������$n��$l", 130, 25, 25, 0,},
		{"$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��һʽ������ָ·������$n��$l", 120, 25, 25, 0,},
		{"$N�󳷲����������أ��ӽ���Բ���Σ���������������$wһʽ�����б��¡�������Բ�󣬴���$n��$l", 110, 15, 25, 0,},
		{"$N�����˲������ֽ�ָ��ת������һŤ���������������$wһ�ǡ�����������������ָ��$n��$l", 150, 35, 45, 0,},
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
		return notify_fail("�������������");
	if (me->query_skill("force", 1) < 20)
		return notify_fail("����ڹ����̫ǳ��");
	if (me->query_skill("unarmed", 1) < 20)
		return notify_fail("��Ļ���ȭ�Ż��̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 20)
		return notify_fail("��������������䵱������");
	me->receive_damage("hp", 10);
	return 1;
}

SKILL_END;
