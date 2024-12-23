
// mahayana.h ������͹�
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSmahayana);

virtual void create()
{
	set_name( "������͹�");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	char msg[255];

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
    
	if (DIFFERSTR(me->querystr("family/family_name"), "������"))
       return notify_fail("�㲻�Ƕ��ҵ��ӣ���������������͹���");

    if (me->query("repute") < 0 )
       return notify_fail("���а��̫�أ��޷�����������͹���");

    if(me->query_skill("taoism",1) > 1)
       return notify_fail(snprintf(msg, 255, "������%sѧ��ţ���ӵĹ�����ôȴ��ѧ������͹���", query_respect(me)));
    if( me->query_skill("poison",1) > 1 )
      return notify_fail("��ѧ��а�Ŷ������޷�����������͹���");

    return 1;
}


SKILL_END;




