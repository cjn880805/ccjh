CONDITION_BEGIN(CCsnake_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_damage("hp", 10);
	duration --;
	tell_object(me, "$RED���е��߶������ˣ�");
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}

CONDITION_END;