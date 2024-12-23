//qinshi.h

//Sample for room: 华山寝室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_qinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "寝室");
	
	add_npc("pub_lady3");           //add by zdn 2001-07-20


	add_door("华山有所不为轩", "华山有所不为轩", "华山寝室");

    set("long","这里是岳不群的寝室，岳不群在江湖上人称「君子剑」，他虽为一大派掌门，可他的卧室却布置的很简单。除了一张床，几只箱子，墙角有张化妆台，只有靠墙一张红木书桌(desk)还显得略有气派");
	

/*****************************************************
     set("exits", ([
            "south" : __DIR__"buwei1",
        ]));
	set ("item_desc", ([
		"desk" : 
    "这是一张很结实的红木书桌，桌面上摆着几只狼毫笔，磨了一半的墨，\n"
    "还有一叠未用的白纸。\n"
	])  ) ;

********************************************/
};


ROOM_END;
