CONDITION_BEGIN(CClinji_longhe);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "��Ȼ�����ȫ��������ģ�����СָͷҲ���붯�ˣ�ԭ���������ׯ�չ��ˣ�");
		me->add("con", - me->query("linji/con"));
		me->del("linji/con");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;