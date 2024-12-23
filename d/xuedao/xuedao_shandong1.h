//shandong1.h

//Sample for room:  血刀门山洞1
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_shandong1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山洞1");

	add_npc("xueshan_xuedao");
	add_npc("xueshan_baoxiang");

	CBox * box = Add_Box();
	box->add_object("dachang", 1);	
	box->set_name( "铁柜");	

	add_door("血刀门大雪山山谷8", "血刀门大雪山山谷8", "血刀门山洞1");

	set("long","空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。");

/******************************************************************************
        set("exits",([
                "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"obj/dachang" :1,
        ]));
******************************************************************************/
};


ROOM_END;
