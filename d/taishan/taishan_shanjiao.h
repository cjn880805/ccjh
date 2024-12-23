//shanjiao.h

//Sample for room: 泰山山脚
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山山脚");

	add_npc("wiz_guard");

	add_door("泰山岱宗坊", "泰山岱宗坊", "泰山山脚");
	add_door("黄河岸边5", "黄河岸边5", "泰山山脚");
	add_door("泰山大驿道", "泰山大驿道", "泰山山脚");

	set("no_fight", 1);

/*****************************************************
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yidao3",
	]));
	
*****************************************************/
};


ROOM_END;
