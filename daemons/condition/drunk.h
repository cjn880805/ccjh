CONDITION_BEGIN(CCdrunk);

virtual int update_condition(CChar *me, LONG & duration)
{
	int limit;
	char msg[255];

	limit = (me->query("con") + me->query("max_mp") / 50) * 2;

	if( duration > limit &&	me->Query(IS_LIVING))
	{
		me->unconcious();
		return 0;
	} 
	else if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$N���˸�����������Ȼ�������ࡣ", me);
	} 
	else if( duration > limit/2 ) 
	{
		tell_object(me, "��������л�������������ƮƮ�أ���������ˡ�");
		tell_room(me->environment(), snprintf(msg, 255, "%sҡͷ���Ե�վ��վ���ȣ���Ȼ�Ǻ����ˡ�", me->name()), me);
		me->receive_damage("hp", 10);
	} 
	else if( duration > limit/4 ) 
	{
		tell_object(me, "�����һ������ϳ壬��Ƥ��Щ�����ˡ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s�����Ѿ����Ծ����ˡ�", me->name()), me);
		me->receive_healing("hp", 10);
	}

	if( ! duration ) return 0;

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;