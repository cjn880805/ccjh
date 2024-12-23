//jmqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_jmqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "巨木旗大厅");

	add_npc("mingjiao_wensong");

	add_door("天微堂", "明教天微堂", "巨木旗大厅");
	add_door("天微堂", "明教天微堂", "巨木旗大厅");

	set("long", "这里是明教巨木旗的大门，庄严古朴，门前对插四面镶绿游龙旗。碧绿的大门敞开着，似乎看不出有何设防。从门里望进去，只有一片苍翠的树林。");;
    

/*****************************************************
	set("exits", ([
		"down" : __DIR__"jmqshenmu",
	]));
        set("objects",([
                __DIR__"npc/wensong":1,
	]));
********************************************/

};



ROOM_END;
