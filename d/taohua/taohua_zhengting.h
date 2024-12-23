//zhengting.h

//Sample for room: 桃花岛山庄正厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花岛山庄正厅");

	add_npc("zm_taohua");
	add_npc("pub_chenlingsu");

	add_door("桃花山庄小院", "桃花山庄小院", "桃花岛山庄正厅");
	add_door("桃花岛卧房", "桃花岛卧房", "桃花岛山庄正厅");
	add_door("桃花岛道具房", "桃花岛道具房", "桃花岛山庄正厅");
	add_door("桃花山庄正门", "桃花山庄正门", "桃花岛山庄正厅");

	set("long", "这里是桃花山庄的正厅。整个大厅十分宽阔。厅中挂满了各种名家的书法真迹。但最显眼的则是正中挂的一幅对联：");

/*****************************************************
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	]) );    
********************************************/
};


ROOM_END;
