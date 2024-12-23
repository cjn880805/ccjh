
// hanbing_strike.h ���溮����
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShanbing_strike);

virtual void create()
{
	set_name( "���溮����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force;
		char damage_type[5];
	}action[] = {
		{"$N˫��һ��һ�С�������ӿ��������ɨ��$n��$l", 30, 200,"����",},
		{"$Nһ�С���ѩ���졹������ͻȻ��ת��������$n��˫������$n��$l", 40, 240,"����",},
		{"$N�������������֣�һ�С�����ѩƮ����Ѹ���ޱȵ�ץ��$n��$l", 50, 280,"����",},
		{"$N����һ����ͻȻһ�С�ǧ����⡹����Ю�溮֮������$n��$l", 60, 300,"����",},
	};
 		
	int level = 0;
	
	for(int i=4; i>0; i--)
	{
		if(( i - 1) * 10 < me->query_skill("hanbing_strike", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
   return notify_fail("�����溮���Ʊ�����֡�");
	if ( me->query_skill("shenghuo_shengong", 1) < 40)
   return notify_fail("���ʥ���񹦻�򲻹����޷������溮���ơ�");
    if ( me->query("max_mp") < 300)
   return notify_fail("�������̫�����޷���������");
    return 1;

}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
   return notify_fail("�������̫���ˣ�����Ϣһ�°ɡ�");
    if ( me->query("mp") < 8)
   return notify_fail("������������������ơ�");
    if (me->query_skill("hanbing_strike", 1) < 50)
   me->receive_damage("hp", 20);
    else
   me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;

}

 
SKILL_END;
