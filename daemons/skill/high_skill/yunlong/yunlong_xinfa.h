// yunlong_xinfa.c �����ķ�

FORCE_BEGIN(CSyunlong_xinfa);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�����ķ�ֻ�ܿ��������ߡ�");
}

FORCE_END;
