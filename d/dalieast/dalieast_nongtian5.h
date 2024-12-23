//nongtian5.h

//Sample for room: 大理城农田5
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城农田5");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_nongfu2");/////////////////////////
//	add_npc("animal_cow");


	add_door("大理城步雄部", "大理城步雄部", "大理城农田5");
	add_door("大理城杆栏3", "大理城杆栏3", "大理城农田5");

	set("long", "这是一小块普通的水田，附近有溪流流过，灌溉十分方便。围绕农田的是一片片桑林，摆夷人采桑、养蚕，纺织相当精致的丝织品。西边有所民居。" );
};

RESIDENT_END;
