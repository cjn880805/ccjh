//lovesteps.h ���Ի���
//code by Teapot
//date : 2001-03-10

SKILL_BEGIN(CSlovesteps);

virtual void create()
{
	set_name( "���Ի���");
}

virtual CMapping * query_action(CChar * me)
{
	static struct {
		char action[255];
		int dodge;
	}action[6] = {
		{"$n����ͻȻ���ֳ�һƬ����������$N���������֡�", 10,},
		{"$n��ͷ��̾һ�����������ܣ�$Nһ㶣�ĬĬͣ�֡�", 20,},
		{"$n������$N���е�ȥ��$Nֻ��ͣ�����ӡ�", 30,},
		{"$n�����ã��ã��㡭�����۸��ң���˵������Ȧ�Ѿ����ˣ�$Nһ㶣�ͣ�ֲ�����", 40,},
		{"$n����������һҹ���ް��ն�����ҹ���޺������$N��������һ���˸У�����ͣ����ʽ��", 50,},
		{"$nʲôҲ��˵�������峺��ˮ��Ŀ�⿴��$N��$N����ǧ�ذ�ת������$n��ȥ�ĺ�����", 50,},
	};

	int level;
	level = random(6);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", 1000);

	return & m_actions;
}

virtual int valid_enable(string usage) { return usage == "dodge" ||usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual const char * query_dodge_msg(CChar * me)
{
	query_action(me);
	return m_actions.querystr("action");
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ����������Ի�����");
	me->receive_damage("hp", 0);
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;