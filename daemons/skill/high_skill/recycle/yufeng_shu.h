
// yufeng_shu.h ������
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyufeng_shu);

virtual void create()
{
	set_name( "������");
}
virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("������ֻ�ܿ��������ߡ�");
}

SKILL_END;
