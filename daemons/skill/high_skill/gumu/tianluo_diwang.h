
// tianluo_diwang.h ���޵�����
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CStianluo_diwang);

void create()
{
	set_name( "���޵�����");
}

const char * type() { return "knowledge"; }

int valid_learn(CChar * me)
{
	
	if( me->query_dex() < 20 )
		return notify_fail("�����̫���ѧϰ��Ĺ�ɵ��书��");
	
	if( me->query_int() < 26 )
		return notify_fail("�������̫��ʺ�ѧϰ��Ĺ�ɵ��书��");
	
	return 1;
}

int practice_skill(CChar * me)
{
	return notify_fail("���޵�����ֻ��ͨ����ϰ�����������ȡ�");
}

SKILL_END;
