//zhongting.h

//Sample for room: 衡山钟亭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhongting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山钟亭");
	
	add_npc("pub_daoke");           //add by zdn 2001-07-16


	add_door("衡山奎星阁", "衡山奎星阁", "衡山钟亭");

    set("long","钟亭内设铁钟一口，重九千斤。每逢山洪暴发，鸣钟镇洪，亦以示警，声闻二十里外。  " );
    

/*****************************************************
        set("exits", ([  
           "west"   : __DIR__"kuixingge",
        ]));
********************************************/
};


ROOM_END;
