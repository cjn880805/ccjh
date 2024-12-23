//nongtian4.h

//Sample for room: 大理城农田4
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城农田4");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_nongfu2");
	
	add_door("大理城阳宗镇", "大理城阳宗镇", "大理城农田4");
//	add_door("大理城大杆栏", "大理城大杆栏", "大理城农田4");

	set("long", "一片临湖的稻田，田里积满了水，田埂很高，且干燥，可以供走动，田间挖掘了相当多的引水沟渠。南诏雨水充足，河湖众多，虽然是山地地区，灌溉也不成问题。此去东边有些杆栏民居。" );

};

RESIDENT_END;
