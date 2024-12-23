//marry_room.h

//Sample for room: ����ׯ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_marry_room);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ׯ");

	//add npcs into the room
	add_npc("pub3_hongniang");
	add_npc("pub3_meipo");

	add_door("������ʯ���10", "������ʯ���10", "���ݺ���ׯ");

	//add_npc("wiz_103");
	
	set("no_fight", 1);
	set("no_steal",1);
	set("no_cast",1);
	set("no_say",1);

/*****************************************************
        set("exits", ([
            "east" : __DIR__"road10",
        ]) );
        set("item_desc", ([
            "zhaopai": (: look_zhaopai :),
        ]) );
        set("objects", ([
            __DIR__"npc/hongniang" : 1,
        ]) );
 ********************************************/
};


ROOM_END;
