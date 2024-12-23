CONDITION_BEGIN(CCbandaged);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( me->query("eff_hp") < me->query("max_hp") )
		me->receive_curing("hp", 3);

	if( ! duration ) return 0;
	duration --;

	return CND_CONTINUE;
}

CONDITION_END;