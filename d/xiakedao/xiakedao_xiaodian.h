//xiaodian.h

//Sample for room: ÏÀ¿ÍµºÐ¡³Ôµê
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_xiaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÏÀ¿ÍµºÐ¡³Ôµê");
	add_npc("pub_xiaoer2");

	add_door("ÏÀ¿ÍµºÓ­±ö¹Ý", "ÏÀ¿ÍµºÓ­±ö¹Ý", "ÏÀ¿ÍµºÐ¡³Ôµê");

	

/*****************************************************
         set("exits", ([
                "west" : __DIR__"yingbin",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
        
********************************************/
};


ROOM_END;
