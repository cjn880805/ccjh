
// zhengqijue.h ������
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSzhengqijue);

virtual void create()
{
	set_name( "������");
}
virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("������ֻ�ܿ��������ߡ�");
}

virtual void skill_improved(CChar *me)
{
	int lvl = me->query_skill("zhengqijue", 1);

	if(lvl > 10)
	{
		tell_object(me, "������ĵ���һ������֮����"   );
	    me->add("repute", 5);
	}
}

SKILL_END;
