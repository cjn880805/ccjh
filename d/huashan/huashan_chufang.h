//chufang.h

//Sample for room: 华山厨房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");

	//add npcs into the room
	add_npc("pub_girldizi");

	add_door("华山花园", "华山花园", "华山厨房");

    set("long","这是华山派的厨房，一位华山小师妹正在烧饭。整个房间弥漫着饭菜香。你可以向小师妹要(serve) 些吃的喝的。墙上贴着一张启事(note)。");
	set("ricewater", 5);
	set("no_fight","1");

/*****************************************************
	set("exits",([
		"east" : __DIR__"garden",
	]));
	set("item_desc",([
		"note" : "一粥一饭，当思来之不易。\n",
	]));
	set("objects",([
		__DIR__"npc/girldizi" : 1,
	]));
//	
********************************************/
};


ROOM_END;
