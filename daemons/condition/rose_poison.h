CONDITION_BEGIN(CCrose_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	me->receive_damage("hp", 10);
	duration --;
	tell_object(me, "$HIR你中的火玫瑰毒发作了！");

	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}

CONDITION_END;