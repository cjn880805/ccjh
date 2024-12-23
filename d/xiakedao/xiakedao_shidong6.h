//shidong6.h

//Sample for room: 侠客岛石洞6
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石洞7");
	
	add_npc("baituo_xieyan");        //add by zdn 2001-07-20


	add_door("侠客岛石洞1", "侠客岛石洞1", "侠客岛石洞6");
	add_door("侠客岛石洞7", "侠客岛石洞7", "侠客岛石洞6");

    set("long", "这是一个石洞，略显狭窄，仅容两人并肩而过。顶壁也甚是低矮，伸手便可触及。油灯晃动，在身后拉出长长的阴影。脚步踢嗒石洞彼端响起阵阵回声，感觉有些异样。" );
    

/*****************************************************
        set("exits", ([
                "south" : __DIR__"shidong7",
                "north" : __DIR__"shidong1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp