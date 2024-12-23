//zhurongdian.h

//Sample for room: 祝融殿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_zhurongdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "祝融殿");
	
	add_npc("henshan_liuzf");         //add by zdn 2001-07-20


	add_door("衡山望日台", "衡山望日台", "衡山祝融殿");
	add_door("衡山祝融峰", "衡山祝融峰", "衡山祝融殿");
	add_door("衡山望月台", "衡山望月台", "衡山祝融殿");

    set("long","祝融殿，又名老圣殿，祠火神祝融。花岗石砌墙，铁瓦覆顶，殿宇凌空傲雪，巍然屹立在衡山绝顶。殿门石楹上刻有:  '寅宾日出，峻极于天' ，殿上有'圣德重华'的楣额。现在这里是衡山派掌门行在。" );

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"wangritai",
           "northdown"  : __DIR__"wangyuetai",
           "westup"     : __DIR__"zhurongfeng",
        ]));
	set("objects", ([
		__DIR__"npc/moda" : 1,
	]));
********************************************/
};


ROOM_END;
