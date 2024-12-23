//shidong7.h

//Sample for room: 侠客岛石洞7
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石洞7");
	
	add_npc("wudang_zhangsan");        //add by zdn 2001-07-20


	add_door("侠客岛石洞6", "侠客岛石洞6", "侠客岛石洞7");
	add_door("侠客岛石洞8", "侠客岛石洞8", "侠客岛石洞7");

    set("long", "这是一个石洞，两旁是光滑的石壁，洞内干干净净，一尘不染却不见一人，洞内周围有灯球火把，把石洞照耀明亮非凡。" );
    

/*****************************************************
        set("exits", ([
                "west" : __DIR__"shidong8",
                "north" : __DIR__"shidong6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp