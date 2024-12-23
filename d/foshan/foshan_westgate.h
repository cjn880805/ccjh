//westgate.h
//Sample for room: 佛山西门
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_westgate);
virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山西门");
	set("resident", "佛山");

	add_npc("pub_playboy");
	add_door("佛山", "佛山", "佛山西门");
	add_door("佛山林间道7", "佛山林间道7", "佛山西门");

	set("long", "这里是佛山镇的西门。岭南以西经由广西可至大理。东面一条东西向的大街是佛山镇的主要街道。" );

};

RESIDENT_END;
