CONDITION_BEGIN(CClinji_zhixin);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "��Ȼ��ͷ����е�һ��հף�ԭ�����֮��ׯ�չ��ˣ����ʱ�����Լ����Ǹ���ľ�ϣ�");
		me->add("int", - me->query("linji/int"));
		me->del("linji/int");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;