//xiuxis.h

//Sample for room: ÏÀ¿ÍµºÐÝÏ¢ÊÒ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_xiuxis);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÏÀ¿ÍµºÐÝÏ¢ÊÒ");


	add_door("ÏÀ¿ÍµºÓ­±ö¹Ý", "ÏÀ¿ÍµºÓ­±ö¹Ý", "ÏÀ¿ÍµºÐÝÏ¢ÊÒ");

	
	set("no_fight",1);
    set("no_steal",1);
    set("sleep_room",1);

/*****************************************************
        set("exits", ([
                "east" : __DIR__"yingbin",
        ]));
        
********************************************/
};


ROOM_END;
