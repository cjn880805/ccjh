
// yihun_dafa.h �ƻ��
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSyihun_dafa);

virtual void create()
{
	set_name( "�ƻ��");
}

virtual int valid_learn(CChar * me)
{
	int lvl;
	
	lvl =  me->query_skill("yihun_dafa", 1);
	
	if(  me->query("repute") < 0 )
		return notify_fail("���а��̫�أ��޷������ƻ�󷨡�");
	
	if (  me->query("per") < 20)
		return notify_fail("��ƾ����Ҳ��̶õ����󣿡�");
	
	if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
		if(lvl>me->query("per")*15)
			return notify_fail("���ֻ��ѧ�������ˡ�");
	}
	else
	{
		if(lvl>me->query("per")*5)
			return notify_fail("���ֻ��ѧ�������ˡ�");
	}
	return 1;
	
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("�ƻ��ֻ�ܿ�ѧϰ����ߡ�");
}

SKILL_END;
