//banshan.h

//Sample for room: 衡山半山亭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_banshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山半山亭");
	
	add_npc("pub_guest");        //add by zdn 2001-07-14

	add_door("衡山山路4", "衡山山路4", "衡山半山亭");
	add_door("衡山山路5", "衡山山路5", "衡山半山亭");

    set("long","终于到了半山亭。这里离到祝融峰无论高程还是行程，均恰好是一半之径，路边小亭显然已极古久，但仍为过往客旅遮风避雨。" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanlu4",
           "northup"    : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
