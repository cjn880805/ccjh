//jiulou1.h

//Sample for room: Îä¹¦¾ÆÂ¥
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_jiulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Îä¹¦¾ÆÂ¥");
	add_npc("pub_xiaoer2");


	add_door("Îä¹¦", "Îä¹¦", "Îä¹¦¾ÆÂ¥");
	add_door("Îä¹¦¾ÆÂ¥¶þÂ¥", "Îä¹¦¾ÆÂ¥¶þÂ¥", "Îä¹¦¾ÆÂ¥");

	

/*****************************************************
        set("exits", ([
                "south" : __DIR__"beijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
********************************************/
};


WUGONG_END;
