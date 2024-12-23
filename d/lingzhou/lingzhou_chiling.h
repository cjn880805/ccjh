//chiling.h

//Sample for room: 灵州赤陵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_chiling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州赤陵");
	
	add_npc("pub_xixiabing");       //add by zdn 2001-07-14


//	add_door("灵州西夏王陵", "灵州西夏王陵", "灵州赤陵");
//	add_door("灵州德陵", "灵州德陵", "灵州赤陵");


};


ROOM_END;
