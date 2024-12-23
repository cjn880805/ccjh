CONDITION_BEGIN(CCjing_curing);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( me->query("eff_hp") < me->query("max_hp") )
        me->receive_curing("hp", 3);

	duration --;
    if( !duration ) return 0;

	return CND_CONTINUE;
}

CONDITION_END;