// wudu-xinfa

FORCE_BEGIN(CSwudu_xinfa);

virtual void create()
{
	set_name( "�嶾�ķ�");
}


virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if( me->query("repute") < 1000 )
		return notify_fail("��ϰ�嶾�ķ������ĺ��������С�");

	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�嶾�ķ�ֻ�ܿ��������ߡ�");
}

FORCE_END;