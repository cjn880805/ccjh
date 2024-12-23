//buwei1.h

//Sample for room: 华山有所不为轩
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_buwei1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山有所不为轩");
	
	add_npc("huashan_doctor");        //add by zdn 2001-07-20


	add_door("华山群仙观", "华山群仙观", "华山有所不为轩");
	add_door("华山寝室", "华山寝室", "华山有所不为轩");
	add_door("华山偏厅", "华山偏厅", "华山有所不为轩");
	add_door("华山花园", "华山花园", "华山有所不为轩");

	set("long", "这是华山掌门岳不群的居所「有所不为轩」，此处是前厅，厅上挂着「正气堂」三字匾额。厅中很宽敞，却没什么摆设，靠墙放着两把交椅，这里是岳不群议事、授徒的地方，后面是寝室。.");  
 
/*****************************************************
         set("exits", ([  
            "north" : __DIR__"buwei2",
            "south" : __DIR__"qunxianguan",
            "west"  : __DIR__"garden",
            "east"  : __DIR__"buwei3",
	]));
        set("objects", ([
             __DIR__"npc/dayou": 1,
             __DIR__"npc/little_monkey": 1,
        ]) );
********************************************/
};


ROOM_END;
