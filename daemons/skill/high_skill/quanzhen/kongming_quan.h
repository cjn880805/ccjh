
// kongming_quan.h ����ȭ
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSkongming_quan);

virtual void create()
{
	set_name( "����ȭ");
	set("valid_force", "xiantian_qigong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С�����ס�ˡ���˫����ƮƮ�ع���$n$l", 30, 20, 80,"����",},
		{"$N����һƽ,����һ��,һ�С�����ʢ����ֱ��$n��$l", -20, 20, 120,"����",},
		{"$N������$nһת��˫������,һ�С��ղ�װˮ������$n$l",25 , 20, 160,"����",},
		{"$N����һ��,����һ��,һ�С��黳���ȡ�����$n��$l", -20, 0,200 ,"����",},
		{"$Nʹһ�С���ɽ�����$n��$l��Χ��$N��������Ӱ֮��", -20, 10, 240,"����",},
		{"$N��ɫһ����ʹ�������Ŀ�������Χ��$n��$l��������",40 , 10, 300,"����",},
	};
 		
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(( i - 1 ) * 10 < me->query_skill("kongming_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
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
        return notify_fail("������ȭ������֡�");
	if ( me->query("max_mp") < 100)
        return notify_fail("�������̫�����޷�������ȭ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 40)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

SKILL_END;
