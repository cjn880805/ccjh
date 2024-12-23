//huixiantai.h

//Sample for room: 恒山见性峰广场
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_huixiantai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山见性峰广场");

	//add npcs into the room
	add_npc("pub_qingbing");

	add_door("恒山见性峰山道2", "恒山见性峰山道2", "恒山见性峰广场");
	add_door("恒山白云庵", "恒山白云庵", "恒山见性峰广场");

    set("long","这里是恒山主峰见性峰峰顶的广场。在这里俯瞰群山，才理会得何以恒山是华夏北方万山之宗，这里也是威震江湖的恒山派的根本重地。 " );

/*****************************************************
        set("exits", ([ 
           "westdown"  : __DIR__"shandao2",
           "north"     : __DIR__"baiyunan",
        ]));
	set("objects", ([
		__DIR__"npc/yi" : 1,
		__DIR__"npc/qing" : 1,
	]));
********************************************/
};


ROOM_END;
