//xinluofang.h

//Sample for room: 新罗坊
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRXiangYang_xinluofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "新罗坊");

	//add npcs into the room
	add_npc("pub_gaoli");/////////////////////////////
				

	add_door("襄阳西北", "襄阳西北", "襄阳新罗坊");

	set("long", "新罗坊，顾名思义是给新罗人住的地方，不过其实现在新罗已经被高丽所灭掉，这里应该叫做高丽坊的。可是大家已经习惯了，于是便还这么叫。这里住着许多高丽商人，也有些高丽的使臣进东京城路过襄阳，便也住在这里。这里的高丽商人总有很多很好的货物，大家都喜欢来买，于是这里就非常的热闹了。" );
/*****************************************************
	set("exits", ([
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/gaoli" : 1,
	]));
********************************************/
};


ROOM_END;
