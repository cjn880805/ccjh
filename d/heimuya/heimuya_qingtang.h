//qingtang.h

//Sample for room: 黑木崖青龙堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_qingtang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖青龙堂");
	
	add_npc("heimuya_jiabaoyu");    //add by zdn 2001-07-20


	add_door("黑木崖山谷", "黑木崖山谷", "黑木崖青龙堂");
	add_door("黑木崖长廊2", "黑木崖长廊2", "黑木崖青龙堂");

	set("long", "这是『日月神教』下第三大堂：青龙堂的大厅，十分气派，又或有一条青龙时隐时现。堂梁上有一块匾(bian)。");
    

/*****************************************************
         set("exits", ([
            "south"      : __DIR__"chlang1",
            "northdown" : __DIR__"guang",
        ]));
        set("item_desc", ([
            "bian": "上面写到：长虹贯日，青龙飞天。千秋万载，一统江湖 。\n",
        ]) );
********************************************/
};


ROOM_END;
