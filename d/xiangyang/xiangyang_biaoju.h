//biaoju.h

//Sample for room: 福威镖局
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_biaoju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福威镖局");

	//add npcs into the room
	add_npc("pub_biaotou");
				

	add_door("襄阳东北", "襄阳东北", "襄阳福威镖局");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
********************************************/
};


ROOM_END;
