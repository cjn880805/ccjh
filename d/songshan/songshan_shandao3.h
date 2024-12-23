//shandao3.h

//Sample for room: 山道3
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山道3");
	
	add_npc("pub_guest");         //add by zdn 2001-07-15


	add_door("嵩山嵩阳书院", "嵩山嵩阳书院", "嵩山山道3");
	add_door("嵩山嵩岳寺", "嵩山嵩岳寺", "嵩山山道3");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"songyuesi",
		"southeast" : __DIR__"shuyuan",
	]));
********************************************/
};


ROOM_END;
