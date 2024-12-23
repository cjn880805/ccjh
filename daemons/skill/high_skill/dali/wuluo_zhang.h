//wuluo_zhang.h  ����������

SKILL_BEGIN(CSwuluo_zhang);

virtual void create()
{
	set_name( "����������");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("���������Ʊ������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N��Ϣ����������һ�ơ��������������������������$n",130 , 20, 0, 0,"����",},
		{"$N����ǳЦ���Ƶ�$n�����������������ӵ$n���䡣$n��ü���㣬$N����һ�С��������ơ���������Ϣ��$n��$l�ĵ�", 150, 20, 30, 20,"����",},
		{"$Nһ�С��̺����Ρ���˫�ƻû���һƬ��Ӱ����һ�����̣���$nϸϸ���ܵ���������", 150, 30,45 , 40,"����",},
		{"$N����Խ��Ȧ�⣬����һ�С��������졹��ԶԶ����$n��$l�����ĳ����ƣ��Ʒ�ε�����Ȼ��ʢֱ��$n����������", 200, 25, 55,60 ,"����",},
		{"$N���ƴ�������Χ��������ƮƮ����$n��ȥ������$n�����мܣ�����ȴ���ؿڼ���Ȧ����һ�С��������������ϳ����ƣ�����$n��$l", 250, 70, 10, 80,"����",},
		{"$N˫�����ƣ�����һ�󾢷磬һ�С�������ɢ����һ�ɿ������$n", 300, 20, 90,100 ,"����",},
	};
 	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuluo_zhang", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�����������Ʊ�����֡�");
 
	if (me->query_skill("kurong_changong",1) < 20)
		return notify_fail("��Ŀ�������̫�����޷������������ơ�");
	
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷������������ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 50)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 20)
		return notify_fail("����������������������ơ�");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="jinyu_quan"; }

SKILL_END;

