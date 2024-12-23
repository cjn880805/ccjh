//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");
	add_npc("taohuadao_yan");
	add_npc("pub_xiangke");

	add_door("桃花山庄小院", "桃花山庄小院", "桃花岛厨房");

	set("long", "这里是桃花山庄的正厅。整个大厅十分宽阔。厅中挂满了各种名家的书法真迹。但最显眼的则是正中挂的一幅对联：");
	set("valid_startroom", 1);
	set("no_beg", "1");

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




