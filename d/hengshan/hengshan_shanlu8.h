//shanlu8.h

//Sample for room: 衡山山路8
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路8");
	
	add_npc("pub_daoke");            //add by zdn 2001-07-17


	add_door("衡山磨镜台", "衡山磨镜台", "衡山山路8");
	add_door("衡山福严寺", "衡山福严寺", "衡山山路8");

    set("long","走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。南边就是福严寺。" );
    

/*****************************************************
        set("exits", ([  
           "southup"  : __DIR__"fuyansi",
           "northup"  : __DIR__"mojingtai",
        ]));
********************************************/
};


ROOM_END;
