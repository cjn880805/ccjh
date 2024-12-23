//riverside1.h

//Sample for room: 江边小路1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "江边小路1");

	//add npcs into the room
//	add_npc("animal_duck");/////////////////////////

	add_door("峨嵋青石阶", "峨嵋青石阶", "万劫谷江边小路1");
	add_door("万劫谷江边小路2", "万劫谷江边小路2", "万劫谷江边小路1");


};


ROOM_END;
