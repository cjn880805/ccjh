//duchang.h

//Sample for room: 赌场
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "赌场");

	//add npcs into the room
	add_npc("pub_xianren");        //add by zdn 2001-07-16
	
	add_door("扬州西南", "扬州西南", "扬州赌场");

	set("long", "这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。西边是赌「大小」的房间，北边是赌「牌九」的房间(建设中)，南面是闽南特有的搏饼娱乐间。墙上显眼处挂着一块牌子(paizi)。" );
	
/*****************************************************
	set("item_desc", ([
		"paizi" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"south": __DIR__"bobing",
	]));
********************************************/
};


ROOM_END;
