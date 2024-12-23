//emei.h

//Sample for room:  ¶ëáÒ
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CREMei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "¶ëáÒ");

	add_npc("pub_daoke");     // add by zdn 2001-07-14
	add_npc("emei_xiaosong");     //add by zdn 2001-07-20

	add_door("¶ëáÒÐ¡Â·", "¶ëáÒÐ¡Â·", "¶ëáÒ");

/******************************************************************************

******************************************************************************/
};


ROOM_END;
