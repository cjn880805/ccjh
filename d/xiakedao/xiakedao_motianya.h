//motianya.h

//Sample for room: 侠客岛摩天崖
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_motianya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛摩天崖");
	
	add_npc("xiakedao_daoseng");        //add by zdn 2001-07-20

	add_door("侠客岛崖底", "侠客岛崖底", "侠客岛摩天崖");
	add_door("侠客岛木屋", "侠客岛木屋", "侠客岛摩天崖");

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits",([
                "east" : __DIR__"mtxiaowu",
                "down" : __DIR__"mtyadi",
        ]));
        set("item_desc",([
                "bei" : "   『摩天崖』  \n无「玄铁令」者禁入！\n",
        ]));
        set("objects",([
                __DIR__"npc/xieyan" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp