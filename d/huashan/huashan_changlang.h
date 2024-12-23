//changlang.h

//Sample for room: 华山长廊
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山长廊");


	add_door("华山花园", "华山花园", "华山长廊");
	add_door("华山居室", "华山居室", "华山长廊");
	add_door("华山松树林", "华山松树林", "华山长廊");

	set("long", "你走在长廊上只见红栏碧瓦，雕梁画栋，廊外风吹翠竹，细吟阵阵，看来华山派气派果然不凡。西面是岳夫人的居室。");  
    
 
/*****************************************************
        set("exits", ([
            "west"  : __DIR__"jushi",
            "north" : __DIR__"songlin1",
            "south" : __DIR__"garden",
        ]));
********************************************/
};


ROOM_END;
