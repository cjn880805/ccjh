//jiulou1.h

//Sample for room: 迎宾楼
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRNanYang_jiulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "迎宾楼");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("南阳城", "南阳城", "南阳迎宾楼");

	set("long", "方圆数百里内提起迎宾楼可以说是无人不知，无人不晓。当年苏学士云游到此，对迎宾楼的素齐赞不绝口，欣然为其题匾，流下一段传遍海内的佳话，从此迎宾楼名声大震。楼下布置简易，顾客多是匆匆的行人，买点包子，鸡腿、米酒就赶路去了。楼上是雅座。" );
	
	set("no_fight", "1");
/*****************************************************
	set("exits", ([
		"east" : __DIR__"nanyang",
		"up" : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-er2" : 1,
	]));
********************************************/
};


ROOM_END;
