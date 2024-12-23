//sanjiaodian.h

//Sample for room: 恒山三教殿
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_sanjiaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山三教殿");
	
	add_npc("hengshan_xian");       //add by zdn 2001-07-20

	add_door("恒山悬空寺", "恒山悬空寺", "恒山三教殿");

    set("long","这里是全寺最高处的三教殿，也是悬空寺最大的殿宇。三层九脊，全部由每根插入崖石的木梁承受，真是 '公输天巧'， 古今奇迹。 " );
    

/*****************************************************
        set("exits", ([ 
           "down"   : __DIR__"xuankong1",
        ]));
********************************************/
};


ROOM_END;
