//yaopu.h

//Sample for room: 药铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药铺");

	//add npcs into the room
	add_npc("pub_huoji");////////////////////////
				

	add_door("襄阳东南", "襄阳东南", "襄阳药铺");

	set("long", "药铺不大，却异常的整洁；正面是柜台，柜台后面是个大柜子几百个小抽屉上一一用红纸标着药材的名称；靠近屋顶的墙上悬着一块黑底金字的匾额，写着“妙手回春”。地下几个伙计正在分拣刚刚收购来的草药。东边一张小矮桌儿，上面放着笔墨纸砚，桌后坐着一位老郎中。一股刺鼻药味充满了整个房间。" );
/*****************************************************
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
********************************************/
};


ROOM_END;
