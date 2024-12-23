//shenheyuan.h

//Sample for room: 终南山神禾原
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shenheyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山神禾原");

	add_npc("pub_seller");

	
	add_door("终南山树林8", "终南山树林8", "终南山神禾原");
	add_door("终南山树林7", "终南山树林7", "终南山神禾原");
	add_door("终南山佛爷掌", "终南山佛爷掌", "终南山神禾原");

    set("long","此处位於终南山中部的翠华山附近。放眼望去，只见一片坦荡无垠的大平原，夹在群山之间。传说商朝末年，姜子牙率兵伐纣攻打长安时，粮草短缺，在此获神禾老汉之助，得米万斛，因此命名为神禾原。往东南和北上各是一片树林。往南是一处遗迹。" );

/*****************************************************
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin7",
                "southeast" : __DIR__"shulin8",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/seller": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
