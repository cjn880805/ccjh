//music.h ����֮��

SKILL_BEGIN(CSmusic);

void create()
{
	set_name( "����֮��");
}

CMapping * query_action(CChar * me)
{
	static CMapping m;
	
	m.set("action", "$N����$w����$n��ȥ��");
	m.set("dodge", -20);
	m.set("damage", 1);
	
	return & m;
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

/*	if(who1 && me->query_skill("music", 1)>=300)
		return notify_fail("�������Ŀǰ�Ĺ���������֮���Ѿ��޷�����ָ���ˡ�");
	
	if(me->query_skill("music", 1)>=300)
		return notify_fail("����Ŀǰ�Ĺ���������֮���Ѿ��޷���������ˡ�");
*/
	return 1;
}

SKILL_END;



