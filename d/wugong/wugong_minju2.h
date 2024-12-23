//minju2.h

//Sample for room: 武功民居2
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_minju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武功民居2");
	
	add_npc("pub_boy");       //add by zdn 2001-07-16


	add_door("武功", "武功", "武功民居2");

	

/*****************************************************
        );
        set("exits", ([
                "east" : __DIR__"beijie",
        ]));
        set("item_desc", ([
        "hua": "这不是北宋范宽的‘溪山行旅图’吗？你大吃一惊。揉了揉眼睛仔细一看，原来是副赝品。\n"
        ]) );
        
********************************************/
};


WUGONG_END;
