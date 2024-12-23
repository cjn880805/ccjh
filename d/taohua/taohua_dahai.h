//dahai.h

//Sample for room: 桃花岛大海
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花岛大海");
	add_npc("taohua_jiguan");        //add by zdn 2001-07-20

			
	add_door("桃花岛", "桃花岛", "桃花岛大海");
	add_door("嘉兴南门", "嘉兴南门", "桃花岛大海");


/*****************************************************
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp