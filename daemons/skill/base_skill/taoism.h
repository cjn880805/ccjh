//taoism.h��ѧ�ķ�

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CStaoism);

virtual void create()
{
	set_name( "��ѧ�ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn ( CChar *me )
{
	int lvl;
	
	lvl = me->query_skill("taoism", 1);
	
 	if(EQUALSTR(me->querystr("gender"), "����") && lvl > 39)
		return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����");
		
	if(EQUALSTR(me->querystr("class"), "bonze"))
		return notify_fail("������%s������ţ���ôȴ��ѧ�����ķ���", query_respect(me));
	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("��ѧ�ķ�ֻ�ܿ�ѧϰ����ߡ�");
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp