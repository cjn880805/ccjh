//dating.h

//Sample for room: 灵鹫独尊厅
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫独尊厅");

	add_npc("lingjiu_xuzhu");
	add_npc("zm_lingjiu");
	add_npc("pub_xiangke");

	add_door("灵鹫画廊15", "灵鹫画廊15", "灵鹫独尊厅");
	add_door("灵鹫独尊厅大门", "灵鹫独尊厅大门", "灵鹫独尊厅");

	set("long", "这就是『灵鹫宫』独尊厅。大厅全是以巨石砌成，石块之间竟无半点缝隙，令人称奇。厅内矗立着四根石柱，皆为坚硬的花岗石所制。" );
	set("valid_startroom", 1);

/*****************************************************
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));
	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
	]));
********************************************/
};


ROOM_END;




