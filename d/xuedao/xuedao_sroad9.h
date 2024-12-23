//sroad9.h

//Sample for room:  血刀门大雪山山谷9
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad9);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门大雪山山谷9");

	add_npc("xueshan_shengdi");


	add_door("血刀门山洞2", "血刀门山洞2", "血刀门大雪山山谷9");
	add_door("血刀门忘忧谷", "血刀门忘忧谷", "血刀门大雪山山谷9");

	set("long","山谷里遍地积雪，四周都是峭壁。只北面有一个出口，东面似乎有个山洞。");

/******************************************************************************
        set("exits",([
                "northdown" : __DIR__"wangyougu",
                "east"      : __DIR__"shandong2",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/shengdi" :1,
        ]));
******************************************************************************/
};


ROOM_END;
