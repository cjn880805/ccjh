//xuedao_xinfa.h ѩ���ķ�

FORCE_BEGIN(CSxuedao_xinfa);

virtual void create()
{
	set_name( "Ѫ���ķ�");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("xuedao_xinfa", 1);
	int t = 1, j;

	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ����������������������Ѫ���ķ���");
	
	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����");
	
	if(lvl<=100)
	{
		if (lvl > 10 && me->query("repute") > t * -5) 
			return notify_fail("���ɱ��̫���ˡ�");
	}

	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("Ѫ���ķ�ֻ������̵������������ȡ�");
}

FORCE_END;
