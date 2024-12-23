//jmqdating.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_jmqdating);

virtual void create()			//Call it when Room Create
{


	set_name( "明教巨木旗大厅");

	add_npc("mingjiao_wensong");

	add_door("明教青石大道8", "明教青石大道8", "明教巨木旗大厅");

	set("long", "这是巨木旗的大厅，虽然都是练武之人，这里却布置得古色古香。整个大厅就建在神木之中，树木掩映，极为严密。虽然未免挤迫，却绝无外敌能轻易攻得上来。厅中充满茶香和古木幽香，十分动人。掌旗使闻松神色自若地端坐喝茶，全不理会客人的到来。巨木旗下在厅口准备了极多的巨木桩，专候来敌");;
    

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
