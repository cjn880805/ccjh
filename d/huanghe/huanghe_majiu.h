//majiu.h

//Sample for room: 黄河马厩
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河马厩");

	//add npcs into the room
//	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
	add_npc("pub_mafu");

				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("黄河客店", "黄河客店", "黄河马厩");

	set("long","这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔槽。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。");
	set("no_fight", "1");
	set("no_beg", "1");
	

/*****************************************************
	set("outdoors", "huanghe");
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
          灵州城:  ridelz

TEXT]));
	set("exits",([ 
	    "east"      : __DIR__"kedian",
	]));
********************************************/
};


CHANGAN_END;
