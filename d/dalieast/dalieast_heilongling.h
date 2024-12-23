//heilongling.h

//Sample for room: 大理城黑龙岭
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_heilongling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城黑龙岭");

	set("resident", "黑龙岭");

	add_npc("pub_xiaozei");
	add_npc("pub_daoke");       //add by zdn 2001-07-12

	add_door("大理城林间小道1", "大理城林间小道1", "大理城黑龙岭");
	add_door("大理城林间小道2", "大理城林间小道2", "大理城黑龙岭");
	add_door("大理城树林外", "大理城树林外", "大理城黑龙岭");

	set("long", "黑龙岭上有红梅二株，干已剥蚀贻尽，仅存枯皮，古质斑斓，横卧于地，离奇乔异，如骄龙，如横峰，而花朵攒躜，又如锦片，如火球，清芳袭人，不知植自何代，相传以为唐梅，疑或然也。南面就是黑龙潭。" );
	
};


RESIDENT_END;
