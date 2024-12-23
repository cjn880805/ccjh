//feifeng_whip.h  �ɷ�޷�

SKILL_BEGIN(CSfeifeng_whip);

virtual void create()
{
	set_name( "�ɷ�޷�");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("�ɷ�޷��������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char weapon[10],damage_type[5];
	}action[] = {
		{"$N����Ծ��һ�С����չ�᡹������$w���¶��ϣ�����$n������", 100, 0,20 ,15 ,"���չ��","����",},
		{"$Nһ�С��ʷ����ࡹ������$wֱ����$n��$l", 110, -10, 30, 20,"�ʷ�����","����",},
		{"$Nһ�С��������������$w�ڿ�һ��һ���������࣬�͵���$n��ͷ����", 120, -15, 40, 40,"�����","����",},
		{"$N̤��һ��������$n��٬һЦ������$wȴ����ͣ����һ�С�����Ϸ���ɨ��$n��$l",130 , -30, 60, 50,"����Ϸ��","����",},
		{"$NԾ�ڰ�գ�һ�С����ɷ��衹������$w������ϴ�գ�����Ϸ�����������ֵ�$n����", 150, -35, 70, 60,"���ɷ���","����",},
		{"$N��ǰ����������$wȦת��磬һ�С�������项������$nǰ��", 170, -40,85 , 75,"�������","����",},
	};
 
  
	int level = 0;
	for(int i=6; i>0; i--)
	{
		
		if(action[i - 1].lvl < me->query_skill("feifeng_whip", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="whip" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

 	if (me->query_skill("kurong_changong",1)< 20)
		return notify_fail("��Ŀ����������̫ǳ��");
	
 	if ( DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("����ү��ѧ��ɷ�ޣ����ʲ���ɡ�");

	if ( !(weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("���������һ�����޲������޷���");
 
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if ( !(weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("��������������ɷ�޷���");

	me->receive_damage("hp", 10);
	return 1;
}

SKILL_END;

/*********
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }
********/