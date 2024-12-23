//shanlu14.h

//Sample for room: 衡山山路14
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路14");
	
	add_npc("pub_gongzi");           //add by zdn 2001-07-17


	add_door("衡山南天门", "衡山南天门", "衡山山路14");
	add_door("衡山藏经殿", "衡山藏经殿", "衡山山路14");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。山路转过芙蓉峰，西面远远看到藏经阁，东南方向通往南天门。" );
    

/*****************************************************
        set("exits", ([ 
           "west"       : __DIR__"cangjingdian",
           "southeast"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
