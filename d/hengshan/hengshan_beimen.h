//beimen.h

//Sample for room: 衡山正北门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山正北门");


	add_door("衡山后殿", "衡山后殿", "衡山正北门");
	add_door("衡山山路1", "衡山山路1", "衡山正北门");

    set("long","南岳大庙正北门是大庙的后门，正在衡山山麓。回望大庙，红墙黄瓦，金碧辉煌。北面是上山的六小路。" );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"houdian",
           "northup": __DIR__"shanlu1",
        ]));
********************************************/
};


ROOM_END;
