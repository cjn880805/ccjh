//fangzhenqiao.h

//Sample for room: 终南山访真桥
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_fangzhenqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山访真桥");

	add_npc("pub_youke2");
	add_npc("pub_manxiangke");     //2001-07-10 zdn add

	add_door("终南山石阶7", "终南山石阶7", "终南山访真桥");
	add_door("终南山遇真宫", "终南山遇真宫", "终南山访真桥");

	set("long","跨过石阶，眼前是一座石头砌成的小小拱桥。桥上栏杆上雕龙描凤，栩栩如生。这里的山势非常陡峻，往下一看，悬崖壁立，脚下白云飘过，真不知身在何境。" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"yuzhengong",
                "southdown" : __DIR__"shijie7",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
