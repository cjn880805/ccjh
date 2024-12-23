//neizhai.h

//Sample for room: 福威镖局内宅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_neizhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福威镖局内宅");

	add_npc("pub_lady3");   // add by zdn 2001-07-13
	add_npc("fuzhou_wang");   //add by zdn 2001-07-20

	add_door("福州福威镖局正厅", "福州福威镖局正厅", "福州福威镖局内宅");


};


ROOM_END;
