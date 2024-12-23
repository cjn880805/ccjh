//chanshi.h

//Sample for room: 禅室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_chanshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺禅室");

	add_npc("xueshan_guoshi");

	add_door("雪山寺大殿", "雪山寺大殿", "雪山寺禅室");

    set("long","这里是僧人门参禅打坐的地方。侧壁一列禅床让人看了就想到该想的事。" );
    set("no_fight",1);
    set("sleep_room",1);
    set("no_steal",1);

/*****************************************************
        set("exits",([
                "southwest" : __DIR__"dating",
        ]));
//        
********************************************/
};


ROOM_END;
