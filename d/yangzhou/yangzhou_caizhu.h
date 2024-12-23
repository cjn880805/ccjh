//caizhu.h

//Sample for room: 财主大门
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_caizhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "财主大门");

	//add npcs into the room
//	add_npc("animal_wolfdog");
	add_npc("pub_guanjia");
	add_npc("pub_jiading");
	add_npc("pub_xiaocui");
	add_npc("pub_yingying");
	add_npc("yunlong_chen");
	
	add_door("扬州西北", "扬州西北", "扬州财主大门");

/*****************************************************
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));
********************************************/
};


ROOM_END;
