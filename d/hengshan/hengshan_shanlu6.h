//shanlu6.h

//Sample for room: 衡山山路6
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路6");
	
	add_npc("pub_daoke");           //add by zdn 2001-07-17


	add_door("衡山山路5", "衡山山路5", "衡山山路6");
	add_door("衡山磨镜台", "衡山磨镜台", "衡山山路6");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。南边山路就是磨镜台和天柱峰。" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"mojingtai",
           "east"       : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
