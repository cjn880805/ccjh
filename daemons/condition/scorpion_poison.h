CONDITION_BEGIN(CCscorpion_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	me->receive_damage("hp", 10);
    duration --;
    tell_object(me, "$HIR你感到呼吸困难，四肢渐渐肿了起来。");

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;