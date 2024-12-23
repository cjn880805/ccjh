//dzdian.h

//Sample for room: 地藏殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dzdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "地藏殿");


	add_door("少林寺广场", "少林寺广场", "少林寺地藏殿");

	set("long", "这是地藏殿。供奉地藏王菩萨。地藏王主宰阴间，手下自然有不少鬼兵鬼卒，罗列帐前。菩萨眉横煞气，手断阴阳。令人一见之下，顿觉心惊胆战，惶恐不已。" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"guangchang5",
	]));
//	set("objects",([
//		__DIR__"npc/mu-ren" : 1
//	]));
//	
********************************************/
};


ROOM_END;
