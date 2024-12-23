CONDITION_BEGIN(CCf_condi);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	duration --;
	
	return CND_CONTINUE;
}

CONDITION_END;