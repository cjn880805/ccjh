CONDITION_BEGIN(CClinji_fengyun);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "��Ȼ�����һ�����������������³�ȥ����ʱ˫�����Ǧ����أ�ԭ����ķ���ׯ�չ��ˣ�");
		me->add("dex", - me->query("linji/dex"));
		me->del("linji/dex");
		return 0;
	}

	duration --;

	return CND_CONTINUE;
}

CONDITION_END;