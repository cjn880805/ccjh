CONDITION_BEGIN(CCiceshock);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	me->receive_damage("hp", 25);

	duration --;
	tell_object(me, "你中的意寒掌毒发作了！");
	return CND_CONTINUE;
}

CONDITION_END;