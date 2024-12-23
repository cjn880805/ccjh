//sushe.h

//Sample for room: 雷门宿舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_sushe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "明教雷门宿舍");


	add_door("明教四门广场", "明教四门广场", "明教雷门宿舍");
	add_npc("mingjiao_leimen");

	set("long", "走进这间宿舍，满目异国情调。雷门教众似乎不大理睬你。许是言语不通，你也不想在此多留。");
    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
    set("exits", ([
        "out" : __DIR__"mjleimen1",
    ]));
********************************************/
};


ROOM_END;
