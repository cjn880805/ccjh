//shandao4.h

//Sample for room: 山道4
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山道4");
	
	add_npc("pub_xianghuo");              // add by zdn 2001-07-15


	add_door("嵩山嵩岳寺", "嵩山嵩岳寺", "嵩山山道4");
	add_door("嵩山法王寺", "嵩山法王寺", "嵩山山道4");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
********************************************/
};


ROOM_END;
