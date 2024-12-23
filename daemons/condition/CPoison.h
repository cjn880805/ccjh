CONDITION_BEGIN(CCPoison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( ! me->Query(IS_LIVING) )
	{
		snprintf(msg, 255, "%s痛苦地哼了一声。", me->name());
		MessageVision(me, "chat", msg);
	}
	else 
	{
		snprintf(msg, 255, "%s的身子突然晃了两晃，牙关格格地响了起来。", me->name());
		MessageVision(me, "tell", "忽然一阵刺骨的奇寒袭来，你中的寒毒发作了！");
		MessageVision(me, "chat", msg);
	}
    
	me->receive_damage("hp", 25);
    duration --;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

CONDITION_END;