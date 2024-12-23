//suzhounan.h

//Sample for room:  苏州南
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhounan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州南");

	set("resident", "苏州");

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("pub_playboy");
	add_npc("pub_playboy");

	add_door("苏州中", "苏州中", "苏州南");
	add_door("苏州南门", "苏州南门", "苏州南");

	add_door("苏州书院", "苏州书院", "苏州南");
	add_door("苏州茶馆", "苏州茶馆", "苏州南");
	add_door("苏州留园", "苏州留园", "苏州南");
	add_door("苏州听雨轩", "苏州听雨轩", "苏州南");
	add_door("苏州狮子林", "苏州狮子林", "苏州南");
	add_door("苏州聚宝斋", "苏州聚宝斋", "苏州南");
};

RESIDENT_END;
