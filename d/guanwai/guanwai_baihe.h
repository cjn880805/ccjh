//baihe.h

//Sample for room: 白河
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_baihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白河");

	set("resident", "白河");

	add_npc("guanwai_yuzhenzi");   // add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("关外谷草垛", "关外谷草垛", "关外白河");
	add_door("关外密林1", "关外密林1", "关外白河");

	set("long","这里是长白山下的一个小村，只有四，五间粗陋的小木屋。这里并没有固定的居民，木屋都是进山采参的参客所盖，为的是在进山前能在这里好好的休息一下。东面就是巍峨耸立的长白大山。" );
    

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
********************************************/
};


RESIDENT_END;
