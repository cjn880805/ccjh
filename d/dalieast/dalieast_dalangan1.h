//dalangan1.h

//Sample for room: 大理城大杆栏
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dalangan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城大杆栏");

	//add npcs into the room
//	add_npc("animal_shanyang");
//	add_npc("animal_shanyang");
//	add_npc("animal_shanyang");
//	add_npc("animal_cow");
//	add_npc("animal_cow");

//	add_door("大理城农田4", "大理城农田4", "大理城大杆栏");

	set("long", "依着一棵大榕树，摆夷人在此建了一座相当大的杆栏。下层这里有一满圈的十几头牛羊。旁边的楼梯修得颇宽。看来这里是本地的体面人家。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


ROOM_END;
