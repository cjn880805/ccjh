//kongdi.h

//Sample for room: 林中空地
//coded by zouwenbin
//data: 2000-11-21

ROOM_BEGIN(CRLingZhou_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "林中空地");

	//add npcs into the room
//	add_npc("animal_wolfdog");/////////////////////////

        add_npc("animal_dushe");        //add by zdn 2001-07-14

	add_door("灵州林中土路", "灵州林中土路", "灵州林中空地");
	add_door("灵州林中大屋", "灵州林中大屋", "灵州林中空地");
	add_door("灵州清新泉", "灵州清新泉", "灵州林中空地");

};


ROOM_END;
