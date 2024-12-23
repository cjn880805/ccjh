//tangshoudao.h  ���ֵ�

//coded by 55
//data: 2000-3-28

SKILL_BEGIN(CStangshoudao);

void create()
{
	set_name( "���ֵ�");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force;
			char damage_type[5];
	}action[]={
		{"ֻ��$N����һ�������һ����һ����ȭ�й��оص���$n�ı��Ӵ��˹�ȥ", 5, 5, 90, "����",},
		{"$N��ǰһ������ϥ������Ȼײ�����ҽ�˳��ɨ��$n��ͷ����", 5, 5, 60, "����",},
		{"$N�ҽ���$n����һ�ߣ�˳�Ƹ߸߾������£��Ÿ���������$n������", 5, 5, 60, "ץ��",},
		{"$N�����ת����Ųȵ���ת���ҽŻ�ɨ��һ�л������Ʋ��ɵ��ػ���$n", 5, 5, 80, "����",},
		{"ֻ��$N����һ������ǰһ�С�һ������������װ��$nһ�ƣ�����ȴ��һ��������������ͼ��$nˤ��", 5, 5, 70, "����",},
		{"$N���һ�������ҵķ��ߣ�\n�߸�������һȭ������һ����$n���Ų��˹�ȥ", 5, 5, 120, "����",},
		{"$N��ǰһ������$n��ͻȻ�����Ծ�𣬰�ջؽ�ɨ��$n����", 5, 5, 50, "����",},
		{"ֻ��$N����������һ����ȭ����$n$l������һȭ�߹�һȭ��\n��һ�е����ֻ��൱������������������ȭ��",5, 5, 80,  "����",},
		{"$Nץס$n�����֣���ǰһ������ָ���Ĵ���$n���۾�", 5, 5, 50, "����",},
		{"$Nһ��ת�����ƻ��أ������ֵ���$n��ͷһ��", 5, 5, 90, "����",},
		{"$N����Ծ��һ������$n���ţ�ȴ�Ǹ����С�\n˵ʱ����ʱ�죬ֻ��$N�����һ��ת����һ���ѵ���$n����ǰ", 5, 5, 100, "����",},
	};
		
	int level = random(11);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
		
	return & m_actions;
}


virtual int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("�����ֵ�������֡�");

    return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" ||  usage=="unarmed" ||usage=="parry";}
virtual int valid_combine(string combo) { return combo=="changquan"; }

int practice_skill(CChar * me)
{
	if( me->query("hp") < 30 )
     return notify_fail("����������������Ϣһ�������ɡ�");
   
	if( me->query("mp") < 10 )
		return notify_fail("������������ˡ�");

	me->receive_damage("hp", 30);
	me->add("mp", -10);

	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

