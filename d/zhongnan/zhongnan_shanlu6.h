//shanlu6.h

//Sample for room: 终南山山路6
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路6");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("quanzhen_daotong");

	add_door("终南山山路7", "终南山山路7", "终南山山路6");
	add_door("终南山山路5", "终南山山路5", "终南山山路6");
	add_door("终南山白马潭", "终南山白马潭", "终南山山路6");

	set("long","这条山路盘终南山主峰而上，山路贴着石璧凿出，只容一人可过，形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收眼底，顿时令人豪气陡声，想要长啸一声。往东下和北上各是一条山路。往南下是白马潭。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"shanlu5",
                "eastdown"   : __DIR__"shanlu7",
                "southdown"  : __DIR__"baimatang",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
