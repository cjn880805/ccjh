// swsb_whip.h ����������
//code by cat
//date : 2001-4-2

SKILL_BEGIN(CSswsb_whip);

virtual void create()
{
	set_name( "����������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С��޿ײ��롹��$n��ǰ���ᶼ��$w��Ӱ��ͬʱ��$nȫ�������Ѩ", 200, 5, 0 ,"����",},
		{"$Nһ�С�����������������$w����$n�����ƫ��Ѩ����", 300, 5,50 ,"����",},
		{"$Nһ�С�������Ϊ����$wר��$n��������֮����", 350,15 , 100,"����",},
	};
	
	int level = 0;
	
	for(int i=3; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("swsb_whip", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "whip") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("��������������Ҫһ���������");
	if (me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�ѧϰ���������֡�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˣ��������������֡�");
	me->receive_damage("hp", 5);
	return 1;
}



SKILL_END;
