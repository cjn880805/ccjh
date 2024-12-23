//chaotian.h

//Sample for room: 朝天门
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_chaotian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "朝天门");
	
	add_npc("pub_jianke");           //add by zdn 2001-07-15 
	add_npc("songshan_sha");         //add by zdn 2001-07-20 


	add_door("嵩山山道5", "嵩山山道5", "嵩山朝天门");
	add_door("嵩山山道6", "嵩山山道6", "嵩山朝天门");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
********************************************/
};


ROOM_END;
