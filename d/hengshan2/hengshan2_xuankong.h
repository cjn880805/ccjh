//xuankong.h

//Sample for room: 恒山悬空寺
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_xuankong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山悬空寺");

	//add npcs into the room
	add_npc("pub_yafu");

	add_door("恒山三教殿", "恒山三教殿", "恒山悬空寺");
	add_door("恒山梯式栈道", "恒山梯式栈道", "恒山悬空寺");
	add_door("恒山翠屏山道2", "恒山翠屏山道2", "恒山悬空寺");

    set("long","这里是悬空寺的北门楼，也是北碑亭。登楼俯视，如临深渊，谷底仰望，如壁间丹凤。向南有悬空栈桥通往南楼。"   );
    

/*****************************************************
	set("exits", ([
		"south"    : __DIR__"zhanqiao",
		"up"       : __DIR__"sanjiaodian",
		"westdown" : __DIR__"cuiping2",
	]));
	set("objects", ([
		__DIR__"npc/yafu" : 1,
	]));
********************************************/
};


ROOM_END;
