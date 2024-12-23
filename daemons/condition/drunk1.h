CONDITION_BEGIN(CCdrunk1);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if(! me->Query(IS_LIVING) ) 
	{
		message_vision("$N���˸�����������Ȼ�������ࡣ", me);
	} 
	else if( me->query("yuandna/jiou/sos_level")>2 && me->Query(IS_LIVING)) 
	{
		tell_object(me, "��͵�һ�ɣ�������ߡ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s���˸������͵�һ�ɣ�������ߡ�", me->name()), me);
		me->unconcious();
		me->set("yuandna/jiou/sos_level",2);
	}
	else if( me->query("yuandna/jiou/sos_level")==2) 
	{
		tell_object(me, "�����ͷ�������ģ�����Ҫ���ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%sҡͷ���Ե�վ��վ���ȣ���Ȼ�Ǻ����ˡ�", me->name()), me);
		me->receive_damage("hp", 10);
	} 
	else if( me->query("yuandna/jiou/sos_level")==1) 
	{
		tell_object(me, "�����ͷ�������ģ�");
		tell_room(me->environment(), snprintf(msg, 255, "%s�����Ѿ����Ծ����ˡ�", me->name()), me);
		me->receive_healing("hp", 10);
	}

	if( ! duration ) return 0;

	duration --;

	time_t t;
	time(&t);
	me->set("yuandna/jiou/time",t);

	return CND_CONTINUE;
}

CONDITION_END;