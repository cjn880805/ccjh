//bingying4.h

//Sample for room: 西兵营
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_bingying4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "西兵营");

	//add npcs into the room
	add_npc("pub_pian");
	add_npc("pub_zuo");
	add_npc("pub_bing");

	add_door("襄阳西北", "襄阳西北", "襄阳西兵营");

/*****************************************************
	set("exits", ([		"south" : __DIR__"westjie3",	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
********************************************/
};


ROOM_END;
