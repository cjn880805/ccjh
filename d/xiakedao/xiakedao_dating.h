//dating.h

//Sample for room: 侠客岛大厅
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛大厅");

	add_door("侠客岛石洞2", "侠客岛石洞2", "侠客岛大厅");
	add_door("侠客岛书房", "侠客岛书房", "侠客岛大厅");
	add_door("侠客岛武器库", "侠客岛武器库", "侠客岛大厅");

    set("no_fight","1");

/*****************************************************
        set("item_desc",([
                "pingfeng" : "这是一个用玉石作的屏风，非常漂亮，也许你能用手把它推(push)开。\n",
        ]));
        set("exits", ([
                "north" : __DIR__"shidong5",
                "east"  : __DIR__"shufang",
                "west"  : __DIR__"wuqiku",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 4,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp