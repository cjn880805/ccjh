//tianroad2.h

//Sample for room: ���޺���ɽɽ·2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺���ɽɽ·2");

	//add npcs into the room
	add_npc("xingxiu_gushou");/////////////////////////
	add_npc("xingxiu_haoshou");
	add_npc("xingxiu_boshou");

				

	add_door("���޺�", "���޺�", "���޺���ɽɽ·2");
	add_door("���޺���ɽɽ·1", "���޺���ɽɽ·1", "���޺���ɽɽ·2");
	add_door("���޺���ɽɽ·3", "���޺���ɽɽ·3", "���޺���ɽɽ·2");


/*****************************************************
        set("exits", ([
            "northup" : "/d/lingjiu/shanjiao",
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"tianroad1",
        ]));
        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
********************************************/
};


ROOM_END;
