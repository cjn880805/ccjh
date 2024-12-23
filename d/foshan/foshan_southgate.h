//southgate.h

//Sample for room: 佛山南门
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_southgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山南门");

	set("resident", "佛山");

	//add npcs into the room
	add_npc("pub_puren");
	
	add_door("佛山", "佛山", "佛山南门");
	add_door("侠客岛海滩", "侠客岛海滩", "佛山南门");


};


RESIDENT_END;
