//xiakedaocity.h

//Sample for room:  侠客岛海滩
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRxiakedaocity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛海滩");
	
	add_npc("pub_yufu");        //add by zdn 2001-07-16


	add_door("侠客岛平原小路", "侠客岛平原小路", "侠客岛海滩");

	add_door("侠客岛石洞", "侠客岛石洞", "侠客岛海滩");

	set("long", "这里就是侠客岛了。北边是一望无际的大海；往南则是一片树林。岛上的空气似乎非常新鲜，咸湿的海风中带着一股花香，这是好大的一片沙滩，东首石崖下停着四十多艘大小的船只(boat)。" );
	

/********************************************************
 
****************************************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp 