//tianweijing.h

//Sample for room: 天威径
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_tianweijing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天威径");

	set("resident", "喜州");

	add_npc("pub_playboy");
	add_npc("pub_youke");   //add by zdn 2001-07-13

	add_door("大理城大路4", "大理城大路4", "大理城天威径");
	add_door("大理城喜州城", "大理城喜州城", "大理城天威径");

	set("long", "此处据说是三国时蜀汉诸葛孔明第七次擒孟获之处，孟获曰：“公，天威也，吾既降，南人不复反也。”，故此得名。这是一条贯通南北的大路，南去十里是喜州城，北上约三十里可达大理城。" );
};

RESIDENT_END;
