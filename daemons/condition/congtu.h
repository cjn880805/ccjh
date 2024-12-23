CONDITION_BEGIN(CCcongtu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;

	me->receive_wound("hp", 10);
    me->receive_damage("hp", 10);
	tell_object(me, "你的体内几种真气互不兼容，仿佛无数把刀子在腹中乱绞！");
	
	duration--;

	return CND_CONTINUE;
}

CONDITION_END;