//shidong8.h

//Sample for room: 侠客岛石洞8
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石洞8");
	
	add_npc("wudang_lisi");        //add by zdn 2001-07-20


	add_door("侠客岛石洞7", "侠客岛石洞7", "侠客岛石洞8");
	add_door("侠客岛山路6", "侠客岛山路6", "侠客岛石洞8");

    

/*****************************************************

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp