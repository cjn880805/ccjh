CONDITION_BEGIN(CClinji_tiandi);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "��Ȼ������ͷ�е�һ��ʧ�䣬ԭ��������ׯ�չ��ˣ����ʱ���к�����ȥ֮̾��");
		me->add("per", - me->query("linji/per"));
		me->del("linji/per");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;