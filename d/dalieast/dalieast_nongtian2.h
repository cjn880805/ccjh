//nongtian2.h

//Sample for room: 大理城农田2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城农田2");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_nongfu");
	add_item("daotian");
//	add_npc("animal_cow");

	add_door("大理城罗伽甸", "大理城罗伽甸", "大理城农田2");
	add_door("大理城农田3", "大理城农田3", "大理城农田2");
	add_door("大理城杆栏", "大理城杆栏", "大理城农田2");

	set("long", "这是一小块普通的水田地，南诏温暖潮湿，自古以来就以种植水稻为主。这附近是大理地区少见的平原地形，主要以耕作为生的摆夷人开垦了一些的农田。田地划分成小块，一些摆夷男子正在田里引着水牛耕作。有道路穿过农田向东而去。" );
	
};


RESIDENT_END;
