//changquan.h  ��ȭ

//coded by Fisho
//data: 2000-11-1

SKILL_BEGIN(CSChangQuan);

virtual void create()
{
	set_name( "��ȭ");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force;
			char damage_type[5];
	}action[]={
		{"ֻ��$N����һ�����������һ���������ڡ���׼$n�ı��Ӻ��������˹�ȥ", 5, 5, 90, "����",},
		{"$N����һ�֣���ȭ������һ�С��β�Ѱ�ߡ�����$n��$l�к���ȥ", 5, 5, 60, "����",},
		{"$N��ȭ��$n����һ�Σ�����ʹ�˸���Ҷ��͵�ҡ���$n��$l����һץ", 5, 5, 60, "ץ��",},
		{"$N����һ������ȭ��������ȭ���磬һ�С��ڻ����ġ��Ʋ��ɵ��ػ���$n$l", 5, 5, 80, "����",},
		{"ֻ��$N������ʽ��һ�С�˫������ʹ�û����з硣����ȴ����һ������$n$l", 5, 5, 70, "����",},
		{"$N������𣬴��һ�����������С������ཻ����\n������$n���һ������ȭ����$n�������˹�ȥ", 5, 5, 120, "����",},
		{"$N�����󹭲���˫��ʹ�˸�������Ʊա���$n��$lһ��", 5, 5, 50, "����",},
		{"ֻ��$N����������һ����ȭ����$n$l������һȭ�߹�һȭ��\n��һ�е����ֻ��൱���ţ�����������������",5, 5, 80,  "����",},
		{"$N����һ�ݣ�����ʹ�˸��������̸���������ɨ��$n��$l", 5, 5, 50, "����",},
		{"$Nһ��ת�����ƻ��أ����Ʒ���ʹ�˸���������ɽ����$n��ͷһ��", 5, 5, 90, "����",},
		{"$N����Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n˵ʱ����ʱ�죬ֻ��$Nһ��������˫���ѵ���$n��$l", 5, 5, 100, "����",},
	};
		
	int level = random(11);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
		
	return & m_actions;
}

int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("����ȭ������֡�");

    return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

int valid_combine(string combo) 
{ return combo=="tangshoudao"; }        


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

