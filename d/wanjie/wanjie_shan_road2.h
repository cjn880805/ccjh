//shan_road2.h

//Sample for room: ɽ·2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_shan_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·4");

	//add npcs into the room
//	add_npc("animal_littlebee");/////////////////////////
        add_npc("animal_snake");        //add by zdn 2001-07-16

	add_door("��ٹ�ɽ·1", "��ٹ�ɽ·1", "��ٹ�ɽ·2");
	add_door("��ٹ�ɽ·3", "��ٹ�ɽ·3", "��ٹ�ɽ·2");

    

/*****************************************************
        set("outdoors", "wanjiegu");
        set("exits", ([  
            "westdown" : __DIR__"shan_road3",
            "eastdown" : __DIR__"shan_road1",
        ]));
        set("objects", ([
            __DIR__"npc/bee" : 2,
        ]));
*****************************************************/
};


ROOM_END;
