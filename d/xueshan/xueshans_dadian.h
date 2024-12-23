//dadian.h

//Sample for room: 大殿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_dadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺大殿");

	//add npcs into the room
	add_npc("pub_xiangke");
	add_npc("xueshan_jiumozhi");
	add_npc("xueshan_fawang");
	add_npc("xueshan_lazhang");
	add_npc("xueshan_samu");
	add_npc("xueshan_jiamu");

	add_door("雪山寺", "雪山寺", "雪山寺大殿");
	add_door("雪山寺禅室", "雪山寺禅室", "雪山寺大殿");
	add_door("雪山寺密室", "雪山寺密室", "雪山寺大殿");
	add_door("雪山寺藏经阁", "雪山寺藏经阁", "雪山寺大殿");
	add_door("雪山寺藏经室", "雪山寺藏经室", "雪山寺大殿");

    set("valid_startroom", 1);

/*****************************************************
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
        ]));
//        
********************************************/
};


ROOM_END;
