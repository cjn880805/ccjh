//shandao6.h

//Sample for room: 山道6
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山道6");
	
	add_npc("pub_poorman");        //add by zdn 2001-07-15      


	add_door("嵩山朝天门", "嵩山朝天门", "嵩山山道6");
	add_door("嵩山峻极禅院山门", "嵩山峻极禅院山门", "嵩山山道6");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"junjigate",
		"southdown" : __DIR__"chaotian",
	]));
********************************************/
};


ROOM_END;
