//shanzhuang.h

//Sample for room: 桃花岛山庄正门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_shanzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花岛山庄正门");

	//add npcs into the room
	add_npc("pub_shitong");/////////////////////////

	add_door("桃花岛", "桃花岛", "桃花岛山庄正门");
	add_door("桃花岛厨房", "桃花岛厨房", "桃花岛山庄正门");
	add_door("桃花岛兵器室", "桃花岛兵器室", "桃花岛山庄正门");
	add_door("桃花岛山庄正厅", "桃花岛山庄正厅", "桃花岛山庄正门");


/*****************************************************
 	set("outdoors", "taohua");
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
		"骑上(ride)就可以飞到中原。\n",
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
//	
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp