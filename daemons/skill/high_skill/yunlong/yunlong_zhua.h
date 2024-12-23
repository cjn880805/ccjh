// yunlong-zhua.c -����צ
SKILL_BEGIN(CSyunlong_zhua);

virtual void create()
{
	set_name( "����צ");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, parry, damage ,lvl;
	}action[] = {
		{"$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l", 150,15,10,10,0,},
		{"$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l", 220, 20, 15, 15, 10,},
		{"$Nһʽ���γ�ӥ�ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ", 250, 20, 20, 20, 20,},
		{"$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����", 290, 25, 20, 30, 30,},

		{"$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�", 350, 30, 25, 40, 40,},
		{"$N���ػ��У�һʽ���������ء�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�", 350, 35, 25, 50, 50,},
		{"$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n", 380, 55, 55, 65, 60,},
		{"$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n", 430, 40, 40, 60, 70,},
		
		{"$N���Ĳ��ض���ʹһʽ��������ˮ�������λ���һ����������$n", 470, 50, 50, 100, 80,},
		{"$N΢΢һЦ��ʹһʽ������ڡ���˫�ֻó�������,ֱ����$n��$l", 470, 60, 60, 100, 90,},
	};
	
	int level = me->query_skill("yunlong_zhua", 1);
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
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
		return notify_fail("�����������������צ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "claw"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("������צ������֡�");
	if (me->query_skill("yunlong_shengong", 1) < 20)
		return notify_fail("��������񹦻�򲻹����޷�ѧ����צ��");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ����צ��");
	if (me->query("max_mp") < 350)
		return notify_fail("�������̫�����޷�������צ��");
	if (me->query_skill("claw",1) <40)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧ����צ��");
	if ( (2*me->query_skill("yunlong_xinfa",1)) <me->query_skill("yunlong_zhua",1))
		return notify_fail("�������צ����򲻹����޷�����ѧ����צ��");
	return 1;
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(me->query_skill("yunlong_shengong") > 70 )
	{
		if( random(me->query_skill("yunlong_zhua")) > 30 )
		{
			victim->apply_condition("zhua_poison", random(me->query_skill("yunlong_zhua")/10 + 1) + 1 +
				victim->query("condition/zhua_poison"));
		}
	}
	
	return 0;
}

virtual int valid_combine(string combo) { return combo=="yunlong_shou"; }

SKILL_END;

/*
mapping *action = ({
});

int valid_combine(string combo) { return combo=="yunlong-shou"; }

*/