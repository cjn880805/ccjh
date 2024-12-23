//square.h

//Sample for room: 华山练武场
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_square);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山练武场");
	
	add_npc("huashan_girldizi");       //add by zdn 2001-07-20


	add_door("华山玉女峰", "华山玉女峰", "华山练武场");
	add_door("华山朝阳峰小路1", "华山朝阳峰小路1", "华山练武场");
	add_door("华山山顶小店", "华山山顶小店", "华山练武场");
	add_door("华山兵器房", "华山兵器房", "华山练武场");
	add_door("华山群仙观", "华山群仙观", "华山练武场");

	set("long", "这里是华山派的练武场，场上立这几个木人，东边是兵器库，西边是个小店。通常有许多华山派弟子在此习武练剑。北边的房屋门上挂着一块匾，上书「群仙观」，西北方似乎有条小道通往山上。");  
 
/*****************************************************
        set("exits", ([  
            "northwest" : __DIR__"chaopath1",
            "south"     : __DIR__"yunu",
            "north"     : __DIR__"qunxianguan",
            "west"      : __DIR__"shop",
            "east"      : __DIR__"bingqifang",
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
********************************************/
};


ROOM_END;
