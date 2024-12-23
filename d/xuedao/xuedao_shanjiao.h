//shanjiao.h

//Sample for room:  血刀门山脚
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_shanjiao);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山脚");

	add_door("血刀门小路4", "血刀门小路4", "血刀门山脚");
	add_door("血刀门山路7", "血刀门山路7", "血刀门山脚");


/******************************************************************************
******************************************************************************/
};


ROOM_END;