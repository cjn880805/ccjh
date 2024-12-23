//damen.h

//Sample for room: 灵鹫独尊厅大门
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫独尊厅大门");

	add_npc("lingjiu_meijian");
	add_npc("lingjiu_lanjian");

	add_door("灵鹫独尊厅", "灵鹫独尊厅", "灵鹫独尊厅大门");
	add_door("灵鹫青石大道2", "灵鹫青石大道2", "灵鹫独尊厅大门");

	set("long", "这就是通向『灵鹫宫』独尊厅的大门。大门左右各有一头石雕的猛鹫，高达三丈有余，尖喙巨爪，神骏非凡，栩栩如生，似乎随时要腾空而去。" );

/*****************************************************
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		__DIR__"npc/lanjian" : 1,
	]));
********************************************/
};


ROOM_END;
