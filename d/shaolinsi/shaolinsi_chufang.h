//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");


	add_door("少林寺斋厅", "少林寺斋厅", "少林寺厨房");

	set("long", "炊烟缭绕，蒸汽腾腾，香味扑鼻而来。靠墙是一排数丈长的灶台，支着十来口大锅，最大的一口饭锅上方竟有人从梁上悬空而下，手持木棍在搅拌。除了烧饭的僧人外，几位火工头陀忙着劈柴运薪，灶下炉火熊熊。一位中年僧人正来回催促着。" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"npc/shaofan-seng" : 2,
	]));
//	
********************************************/
};


ROOM_END;
