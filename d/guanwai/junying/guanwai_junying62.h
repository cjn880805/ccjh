//junying62.h  后军营帐2
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying62);

virtual void create()			
{
	set_name("后军营帐");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("右翼营帐3", "关外右翼营帐3", "关外后军营帐2");
	add_door("后军营帐1", "关外后军营帐1", "关外后军营帐2");
	add_door("中军营帐6", "关外中军营帐6", "关外后军营帐2");
	add_door("后军营帐4", "关外后军营帐4", "关外后军营帐2");

	set("long","后军乃辎重粮草屯放之重地，守卫森严。看得出统帅深得兵家要旨。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐6") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
