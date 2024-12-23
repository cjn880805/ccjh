//poison.h ��������

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSpoison);

virtual void create()
{
	set_name( "��������");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn (CChar *me )
{
	char msg[255];
	if ( DIFFERSTR(me->querystr("family/family_name"), "������")
		&&  DIFFERSTR(me->querystr("family/family_name"), "����ɽ��")) 
       return notify_fail("�㲻�����޵��ӣ�Ҳ���ǰ������ˣ���������������");

    if ((me->query_skill("taoism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1) ||
        (me->query_skill("buddhism",1) > 1))
        return notify_fail(snprintf(msg, 255, "������%s�Ѿ�ѧ���������ɵ��ķ�����ôȴ��ѧ���ǲ��ܵĶ�����", query_respect(me)));
  
	return 1;
}

virtual void skill_improved(CChar * me)
{
    if ((me->query_skill("poison",1) == 50) ||
        (me->query_skill("poison",1) == 60) ||
        (me->query_skill("poison",1) == 70) ||
        (me->query_skill("poison",1) == 80) ||
        (me->query_skill("poison",1) == 90) ||
        (me->query_skill("poison",1) >= 100))
    {
        tell_object(me, "�����ڵĶ��ʿ�ʼ���������ˣ�������ɢ���ˡ�");
        me->apply_condition("poison_sandu",1000);
    }
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp