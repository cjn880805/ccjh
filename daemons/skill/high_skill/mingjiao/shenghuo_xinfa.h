
// shenghuo_xinfa.h ʥ���ķ�
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_xinfa);

virtual void create()
{
	set_name( "ʥ���ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("ʥ���ķ�ֻ��ͨ����������!");
}

SKILL_END;
