CONDITION_BEGIN(CCflower_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_damage("hp", 10);
	duration -= random(5);
	tell_object(me, "$HIR你中的断肠花毒发作了！");

	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}

CONDITION_END;