CONDITION_BEGIN(CClinji_daxiao);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration == 0 )
	{
		tell_object(me, "忽然你全身感到一阵乏力，一肚皮不自在，原来你的大小庄收功了！" );
		me->add("eff_hp", me->query("linji/jing"));
		me->add("hp", me->query("linji/jing"));

		if (me->query("eff_hp") > me->query("max_hp"))
			me->set("eff_hp", me->query("max_hp"));
		if (me->query("hp") > me->query("eff_hp"))
			me->set("hp", me->query("eff_hp"));
		me->del("linji/jing");
		return 0;
	}

	duration --;
	return CND_CONTINUE;
}

CONDITION_END;