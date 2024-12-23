//majiu.h

//Sample for room: 马厩
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");

	//add npcs into the room
//	add_npc("animal_zaohongma");
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
//	add_npc("pub_mafu");				

	add_door("苏州戏园子", "苏州戏园子", "苏州马厩");

	set("long", "这是北大街的马厩，常年供应新鲜草料。苏州民风淳朴，马夫们会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。    马厩中堆放著几堆草料，正中有一口泔槽。 " );
 	set("outdoors", "city");
	set("no_fight", "1");
	set("no_beg", "1");
	
/*****************************************************
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz

TEXT]));
	set("exits",([  
		"east"  : __DIR__"beidajie1",
		"south" : __DIR__"xiyuan",
	]));

********************************************/
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
