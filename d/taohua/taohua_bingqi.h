//bingqi.h

//Sample for room: 兵器室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_bingqi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵器室");

	add_npc("pub_xiangke");

	add_door("桃花岛道具房", "桃花岛道具房", "桃花岛兵器室");

	set("long", "这是一间存放兵器的屋子。刀、枪、剑、戟等各种兵器都按类放在各自的兵器架上。整个屋子落满灰尘，显然已经好久没人来过。");
	set("valid_startroom", 1);
	set("no_beg", "1");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
	]) );
//	
********************************************/
};


ROOM_END;




