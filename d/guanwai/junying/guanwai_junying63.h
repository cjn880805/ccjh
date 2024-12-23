//junying63.h  后军营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying63);

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
	
	add_door("后军营帐1", "关外后军营帐1", "关外后军营帐3");
	add_door("后军营帐4", "关外后军营帐4", "关外后军营帐3");

	set("long","后军乃辎重粮草屯放之重地，守卫森严。看得出统帅深得兵家要旨。" );

};

ROOM_END;
