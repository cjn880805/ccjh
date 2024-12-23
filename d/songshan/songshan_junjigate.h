//junjigate.h

//Sample for room: 峻极禅院山门
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_junjigate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峻极禅院山门");
	
	add_npc("songshan_fei");         //add by zdn 2001-07-20


	add_door("嵩山山道6", "嵩山山道6", "嵩山峻极禅院山门");
	add_door("嵩山封禅台", "嵩山封禅台", "嵩山峻极禅院山门");

	set("long", "嵩山绝顶，古称 '峻极' 。这里是本是佛教大寺，但百年来却已成为嵩山派掌门人的住所。西上可以到达封禅台。" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"chanyuan",
		"westup"    : __DIR__"fengchantai",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
		__DIR__"npc/wan" : 1,
	]));
//	set("outdoors", "songshan");

********************************************/
};


ROOM_END;
