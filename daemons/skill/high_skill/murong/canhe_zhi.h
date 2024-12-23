// canhe_zhi.h �κ�ָ
//code by sound
//date : 2001-06-14

SKILL_BEGIN(CScanhe_zhi);

virtual void create()
{
	set_name( "�κ�ָ");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("�κ�ָ��������Ԫ�����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N���缤����˫ָ������ã�һ�С�Ŀ��ʶ�����׺ݵ���$n��$l��ȥ", 
		100, 5, 10, 0,"����",},
		{"$N���һ����ʮָ���·ַɣ�һ�С������㾦����˫ֱָȡ$n��$l", 
		130, 8, 15, 20,"����",},
		{"$Nʮָ���������ʵ��һ�С���˷���롹��ǰ�����ң�˲Ϣ����$n����������", 
		170, 5, 20, 40,"����",},
		{"$N�����ڿն���һ�С��ܳ���������������죬��$n��$l�Ͳ���ȥ", 
		200, 0, 25, 60,"����",},
		{"$N����һ�������������ߵ�$n��ǰ��һ�С����ϲ�����������$n��$l", 
		220, 15, 30, 70,"����",},
		{"$Nһ�С��˱����᡹������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l", 
		300, 20, 0, 80,"����",},
		{"$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ�С���н��������һ����ɽ������������ֱ��$n$l", 
		360, -5, 0, 90,"����",},
		{"$NͻȻ���м�ת��һ�С����μ�����ʮָ���裬��ʱ֮�佫$n����˷�����ס��", 
		420, -15, 0, 100,"����",},
	};

	int level = me->query_skill("canhe_zhi", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
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

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        	return notify_fail("���κ�ָ������֡�");

	if ( me->query_skill("shenyuan_gong", 1) < 15)
        	return notify_fail("�����Ԫ����򲻹����޷�ѧ�κ�ָ��");

	if ( me->query("max_mp") < 100)
        	return notify_fail("�������̫�����޷����κ�ָ��");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
        	return notify_fail("���������������Ϣһ�������ɡ�");

	if ( me->query("mp") < 10)
        	return notify_fail("��������������κ�ָ��");

	me->receive_damage("hp", 30);
	me->add("mp", -10);

	return 1;
	
}

int valid_combine(string combo) { return combo=="xingyi_zhang"; }

SKILL_END;
