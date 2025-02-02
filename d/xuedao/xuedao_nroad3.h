//nroad3.h

//Sample for room:  血刀门山路3
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山路3");
	
	add_npc("pub_caishiren");            //add by zdn 2001-07-16



				
	add_door("黄河", "黄河", "血刀门山路3");
	add_door("永登宜和堡", "永登宜和堡", "血刀门山路3");

	set("long","这里山势比大雪山东面稍缓，也不是十分的严寒。山道两旁长得有稀稀拉拉的一些野草。四下毫无人迹，只有几只秃鹰在高处盘旋，俯视着茫茫雪山。");

/******************************************************************************
        set("exits",([
                "south"     : __DIR__"nroad4",
                "eastdown"  : __DIR__"nroad2",
        ]));
        set("objects",([
                __DIR__"npc/lutianshu" : 1,
                __DIR__"npc/shuidai"   : 1,
                __DIR__"npc/eagle"     : 2,
        ]));
******************************************************************************/
};


ROOM_END;
