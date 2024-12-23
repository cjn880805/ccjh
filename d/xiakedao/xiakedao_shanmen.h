//shanmen.h

//Sample for room: 侠客岛山门
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛山门");
	
	add_npc("pub_shiwei");         //add by zdn 2001-07-16

	add_door("侠客岛海滩", "侠客岛海滩", "侠客岛山门");
	add_door("侠客岛山路1", "侠客岛山路1", "侠客岛山门");

    set("long", "你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条山径向山上延伸，不时有几个江湖好汉从你身边走过，他们都是到侠客岛来专研武功的。石壁上刻着三个大字 ‘侠客岛’ ，这就是江湖上传闻的侠客岛。" );
    

/*****************************************************
        set("exits", ([
                "southup" : __DIR__"road1",
                "north" : __DIR__"lin8",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2" : 1]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp