//beijing_was.h  北京万安寺

RESIDENT_BEGIN(CRbeijing_was);

virtual void create()
{
	set_name( "万安寺");
	set("resident", "北京");

	add_npc("was_fanseng");
	add_npc("was_fanseng");

	add_door("万安寺外", "北京万安寺外", "北京万安寺");
	add_door("万安寺第一层", "北京万安寺第一层", "北京万安寺");
};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"万安寺第一层") )
	{
		if(!me->query_temp("was/renwu2_5"))
		{
			return notify_fail("$HIR寺门两旁的番僧伸手拦住你的去处：施主，请留步！");
		}
	}
	return CRoom::valid_leave(me, dir);
}
RESIDENT_END;
