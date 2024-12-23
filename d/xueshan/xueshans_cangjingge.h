//cangjingge.h

//Sample for room: 藏经阁
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_cangjingge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺藏经阁");

	add_npc("xueshan_lingzhi");

	add_door("雪山寺大殿", "雪山寺大殿", "雪山寺藏经阁");

    set("long","这里是雪山寺的藏经之处。书架上林林总总都是梵文典籍。你一个字也看不懂。" );

/*****************************************************
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));
//        
********************************************/
};


ROOM_END;
