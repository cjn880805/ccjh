//lamaism.h

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSlamaism);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual char * type() { return "knowledge"; }

virtual int valid_learn ( CChar *me )
{
    if( me->query_skill("taoism",1) > 1 )
      return notify_fail("��ѧ��ţ���ӵ��ķ����޷����������ķ���");
    return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�����ķ�ֻ�ܿ��������ߡ�");
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp