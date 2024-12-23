//guanritai.h

//Sample for room: 终南山观日台
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_guanritai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山观日台");

	//add npcs into the room
	add_npc("pub_youke");/////////////////////////
	add_npc("pub_xiangke");

				
	
	add_door("终南山石阶8", "终南山石阶8", "终南山观日台");

    set("long","这里是终南山上的观日台，不知哪朝哪代何人在这里修筑了这个平台，用来观瞻日出的美景。这里的山势非常陡峻，往下一看，悬崖壁立，脚下白云飘过，真不知身在何境。" );

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
