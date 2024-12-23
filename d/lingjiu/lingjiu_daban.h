//daban.h

//Sample for room: ÁéğÕ×º½õ¸ó
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_daban);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ×º½õ¸ó");


	add_door("ÁéğÕ»­ÀÈ14", "ÁéğÕ»­ÀÈ14", "ÁéğÕ×º½õ¸ó");
	add_npc("lingjiu_qiu");

	

/*****************************************************
        set("exits", ([
            "west" : __DIR__"changl14",
        ]));
        set("item_desc", ([
            "jingzi" : (: look_jingzi :) ,
        ]));
********************************************/
};


ROOM_END;
