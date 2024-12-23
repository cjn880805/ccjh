//chaguan.h

//Sample for room: 茶馆
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "茶馆");

	//add npcs into the room
	add_npc("pub_xiaoer2");//////////////////////////////
				

	add_door("襄阳东北", "襄阳东北", "襄阳茶馆");
//	add_door("襄阳马厩", "襄阳马厩", "襄阳茶馆");

	set("long", "你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排开，坐满了客人，或高声谈论战局，或交头接耳元兵势大。你要想打听什么，恐怕不是时候。" );
	set("resource/water", 1);
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"northjie",
	]));
********************************************/
};


ROOM_END;
