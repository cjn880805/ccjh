CONDITION_BEGIN(CCslumber_drug);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	tell_object(me, "��������л����������пյ����ģ�ֱ��������˯һ����");
	tell_room(me->environment(), snprintf(msg, 255, "%sҡͷ���Ե�վ��վ���ȣ���Ȼ���ɺ�ҩ��ҩ�������ˡ�", me->name()), me);

	duration --;
	me->add_temp("apply/armor",-3);
	me->add_temp("apply/damage",-3);
	me->add_temp("slumber",3);

	if( !duration )
	{
		tell_object(me, "������������������" );
		me->add_temp("apply/armor",me->query_temp("slumber"));
		me->add_temp("apply/damage",me->query_temp("slumber"));
		me->delete_temp("slumber");
		me->UpdateMe();
		return 0;
	}
	me->UpdateMe();

	return CND_CONTINUE;
}

CONDITION_END;