//yaodian.h

//Sample for room: 胡庆余堂
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_yaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "胡庆余堂");

	//add npcs into the room
	add_npc("pub_huqingyu");

	add_door("杭州青石大道14", "杭州青石大道14", "杭州胡庆余堂");

	set("long","这是一家明净宽敞的药堂，後墙上是一个大药柜。几个伙计正忙着爬上爬下地从小抽屉里抓药。药柜前摆着一张桌子，桌旁一位老者正在为人把脉。他就是名医胡庆余。    柜台上方高挂一个大牌子(paizi)." );
	
	set("no_fight", 1);
	set("no_beg","1");

/*****************************************************
         set("exits", ([
            "west"      : __DIR__"road14",
        ]));
        set("objects", ([
            __DIR__"npc/huqingyu" : 1,
        ]));
        set("item_desc", ([
            "paizi" :
	@TEXT
        本店提供下列服务:
    先给胡大夫一百黄金, 然后:
    改名:          name 新名
    叛师:          betrayer
	TEXT]));
//    恢复青春:      age
     
 ********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
