//ermenkan.h

//Sample for room: 二门坎子
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_ermenkan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "二门坎子");

	set("resident", "关外");
	
	add_npc("pub_daoke");           // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外大门坎子", "关外大门坎子", "关外二门坎子");
	add_door("关外满天星", "关外满天星", "关外二门坎子");

	set("long","漫长的参路蜿蜒的消失在原处的天边，路上依稀还留有一些浅浅的足印，看来是前面的参客留下的。白茫茫的雪地反射出耀眼的银光，看得人头昏眼花。偶尔有几只雪兔飞驰而过，转眼就无影无踪了。" );
    

/*****************************************************
	set("exits", ([
		"east"       : __DIR__"mantianxing",
		"northwest"  : __DIR__"damenkan",
	]));
********************************************/
};


RESIDENT_END;
