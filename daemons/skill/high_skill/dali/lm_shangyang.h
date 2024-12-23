//lm_shangyang.h  ������֮ʳָ������

SKILL_BEGIN(CSlm_shangyang);

virtual void create()
{
	set_name( "������֮ʳָ������");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("�����񽣱�������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
		char weapon[10],damage_type[5];
	}action[] = {
		{"$Nһʽ������ӭ�͡����������ϣ�ʳָ����$n���ظ���", 60, -5, -5, 10, 0,"���ν���","����",},
		{"$N���ƻ��أ�һʽ��������ա���ʳָǰ���˸��뻡���͵�һ˦������$n��$l", 120, 5, 10, 20,10 ,"���ν���","����",},
		{"$N����������һʽ���ն���������ʳָ�˲����һ������������$n��ҪѨ", 180,10 , 20,30 , 20,"���ν���","����",},
		{"$N��ϥ������һʽ��������𡹣�������ȭ���⣬����ʳֱָ����ңң����$nһ��", 240, 20, 30, 40, 30,"���ν���","����",},
		{"$N����Ծ�����Ƹ��أ��������ʳָ��һʽ�����������������$nͷ���ٻ�Ѩ��ȥ", 300, 30,40 , 50, 40,"���ν���","����",},
		{"$Nһʽ��ָ�㽭ɽ������ָ�滺���磬����$nһ��", 360, 40, 50, 60, 50,"���ν���","����",},
		{"$N�ֱ۲�����������紵����һ�С�΢�������������$nȫ����Ѩ", 420, 40, 50,70 ,60 ,"���ν���","����",},
		{"$Nٿ��֮���۽���ȥ��һ�С�������š�����$n��һ�����ˣ��鶯�ޱ�", 480, 60, 60, 90, 80,"���ν���","����",},
	};
    
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lm_shangyang", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("��������������֡�");
 
	if (me->query("max_mp") < 150)
		return notify_fail("�������̫�����޷�����������");
	
	if (me->query_skill("liumai_shenjian",1)>0)
		return notify_fail("���������ϲ�����ʹ���ˣ��������һ����");
	
	if (me->query_skill("sun_finger",1)<50)
		return notify_fail("���һ��ָ����������������һ��ָ�ɡ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");

	if (me->query("mp") < 20)
		return notify_fail("������������ˡ�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;

/*********
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }
********/