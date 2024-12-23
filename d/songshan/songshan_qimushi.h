//qimushi.h

//Sample for room: 启母石
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_qimushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "启母石");
	
	add_npc("pub_caishiren");      //zdd by zdn 2001-07-15


	add_door("嵩山山道1", "嵩山山道1", "嵩山启母石");
	add_door("嵩山启母阙", "嵩山启母阙", "嵩山启母石");
	add_door("嵩山山道2", "嵩山山道2", "嵩山启母石");

	

/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"      : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
********************************************/
};


ROOM_END;
