//shijie.h

//Sample for room:  梅庄孤山石级
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄孤山石级");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-14

	add_door("杭州孤山", "杭州孤山", "梅庄孤山石级");

	add_door("梅庄蜿蜒小径", "梅庄蜿蜒小径", "梅庄孤山石级");
	

    

/******************************************************************************
        set("exits", ([  
            "eastdown" : "/d/hangzhou/gushan",
            "north"    : __DIR__"xiaolu.c",
        ]));
******************************************************************************/
};


ROOM_END;
