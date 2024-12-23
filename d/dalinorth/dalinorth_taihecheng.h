//taihecheng.h

//Sample for room: 太和城
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLiNorth_taihecheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "太和城");

	set("resident", "太和");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("pub_lijin");
	add_npc("pub_hongfunv");

	add_door("大理城北门", "大理城北门", "大理城太和城");
	add_door("大理城南诏德化碑", "大理城南诏德化碑", "大理城太和城");

	set("long", "此城是乌夷族的治府，全城巷陌都以石垒成，高丈余，连绵数里不断。太和不算大城，但人口为数并不少，地理上和军事上是大理城的北门户，历代大理王朝都在此加固城池，派驻精兵。附近有一些乌夷部族聚居。此南是一片平原，下十五里便达大理城。" );

};

RESIDENT_END;
