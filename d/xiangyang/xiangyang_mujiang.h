//mujiang.h

//Sample for room: Ä¾½³ÆÌ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_mujiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ä¾½³ÆÌ");

	//add npcs into the room
	add_npc("pub_mujiang");
	add_npc("pub_kangzhongming");
				
	add_door("ÏåÑô¶«ÄÏ", "ÏåÑô¶«ÄÏ", "ÏåÑôÄ¾½³ÆÌ");
/*****************************************************
	set("exits", ([
		"north" : __DIR__"eastjie3",
	]));
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
********************************************/
};


ROOM_END;
