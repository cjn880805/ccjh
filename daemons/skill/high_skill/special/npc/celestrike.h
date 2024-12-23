//celestrike.h  ����

//coded by Fisho
//data: 2000-11-1

SKILL_BEGIN(CScelestrike);

virtual void create()
{
	set_name( "����");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force, damage;
			char damage_type[5];
	}action[]={
		{"$Nʹ��һ�С��컢��ʽ�������ƴ�������$n��$l��",-30,10,100,100,"����",},
		{"$Nʹ��һ�С��컢��ʽ�������ƻ���Ϊʵ����$n��$l��",-10,-30,100,120,"����",},
		{"$Nʹ�������С��컢ɨʽ�������ͻ�������$n��ǰ��һ������$n��$l��",-30,10,70,140,"����",},
		{"$N˫��һ��ʹ�����컢��ʽ������׼$n��$l�����ĳ����ơ�",10,-30,130,140,"����",},
		{"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��컢�ʽ������$n$l��",-20,-30,200,120,"����",},
		{"$Nʹ�����컢��ʽ��������ɢ���ߴ�ͬʱ��$n��$l���ƹ�����",-70,-10,240,110,"����",},
		{"$N����������һ�С������컢��˫�Ʋ����Ƴ���",-70,-40,350,100,"����",},
	};
		
	int level = random(7);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�"},
		{"$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣"},
		{"$n��һת��һ�С���������������$N����$w���֡�"},
		{"$nʹ����ճ���־���˫��һ������ƫ��$N��$w��"},
		{"$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���"},
        {"$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��"},
        {"$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(3)+4];
}


int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("�����Ʊ�����֡�");

    return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="strike" || usage == "parry";
}


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

