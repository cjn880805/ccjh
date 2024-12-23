// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//dodge.h -- ��������

SKILL_BEGIN(CSDodge);

virtual void create()
{
	set_name( "��������");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = 
	{
		"���Ǻ�$p$lƫ�˼��硣",
		"���Ǳ�$p����ض㿪�ˡ�",
		"����$n����һ�࣬���˿�ȥ��",
		"���Ǳ�$p��ʱ�ܿ���",
		"����$n����׼�������Ų�æ�ض㿪��",
	};
	
	return dodge_msg[random(5)];
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

/*	if(who1 && me->query_skill("dodge", 1)>=400)
		return notify_fail("�������Ŀǰ�Ĺ��������������Ѿ��޷�����ָ���ˡ�");
	
	if(me->query_skill("dodge", 1)>=400)
		return notify_fail("����Ŀǰ�Ĺ��������������Ѿ��޷���������ˡ�");
*/
	return 1;
}

SKILL_END;