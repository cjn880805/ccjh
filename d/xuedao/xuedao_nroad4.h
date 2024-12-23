//nroad4.h

//Sample for room:  血刀门山路4
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad4);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山路4");
	
	add_npc("xuedao_huatiegan");        //add by zdn 2001-07-20xuedao_hutiegan
		
	add_door("血刀门山路2", "血刀门山路2", "血刀门山路4");
	add_door("血刀门雪山北麓", "血刀门雪山北麓", "血刀门山路4");

	set("long","大雪山北麓的地势不是甚高，周围还有一些小山丘。西面有一座寺院依山而建。显得异常高大。寺院呈平顶梯型，多由大石砌成，墙体厚实，窗口窄小。");

/******************************************************************************
        set("exits",([
                "north"   : __DIR__"nroad3",
                "westup"  : "/d/xueshan/shanmen",
        ]));
******************************************************************************/
};


ROOM_END;
