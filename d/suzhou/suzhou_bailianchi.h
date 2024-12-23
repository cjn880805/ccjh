//bailianchi.h

//Sample for room: ╟ва╚Ёь
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_bailianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "╟ва╚Ёь");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////

	add_door("кужщ╤Чоим╓", "кужщ╤Чоим╓", "кужщ╟ва╚Ёь");


};


ROOM_END;
