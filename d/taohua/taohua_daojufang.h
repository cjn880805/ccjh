//daojufang.h

//Sample for room: 道具房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_daojufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "道具房");

	//add npcs into the room
	add_npc("pub_yapu");
	
	CBox * box = Add_Box();
	box->add_object("xiangcha", 1);	
	box->set_name( "漆柜");	
	
	add_door("桃花岛山庄正厅", "桃花岛山庄正厅", "桃花岛道具房");
	add_door("桃花岛兵器室", "桃花岛兵器室", "桃花岛道具房");


/*****************************************************
	set("exits", ([
		"west" : __DIR__"dating",
		"up"   : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/yapu"  : 2,
		__DIR__"obj/xiang" : 1,
	]) );
********************************************/
};


ROOM_END;
