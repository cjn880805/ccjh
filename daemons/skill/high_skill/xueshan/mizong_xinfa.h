// mizong-xinfa.c �����ķ�
// by secret
FORCE_BEGIN(CSmizong_xinfa);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�����ķ�ֻ��ͨ����������!");
}

FORCE_END;
