//buddhism.h�����ķ�

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSbuddhism);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn ( CChar *me )
{
	if( me->query("guilty") > 0 )
		return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���");
    return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�����ķ�ֻ�ܿ��������ߡ�");
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp