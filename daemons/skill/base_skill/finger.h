//finger.h����ָ��

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSfinger);

virtual void create()
{
	set_name( "����ָ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$Nһָ����$n�����ϡ�");
	return & m_actions;
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

/*	if(who1 && me->query_skill("finger", 1)>=200)
		return notify_fail("�������Ŀǰ�Ĺ���������ָ���Ѿ��޷�����ָ���ˡ�");
	
	if(me->query_skill("finger", 1)>=200)
		return notify_fail("����Ŀǰ�Ĺ���������ָ���Ѿ��޷���������ˡ�");
*/
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp