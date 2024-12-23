//road14.h

//Sample for room: 林间道14
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道14");

	//add npcs into the room
//	add_npc("animal_hongma");
	
	add_door("佛山林间道13", "佛山林间道13", "佛山林间道14");
	add_door("泉州西门吊桥", "泉州西门吊桥", "佛山林间道14");

	set("long", "这里是一条林间小道，在树丛中蜿蜒。东面就是泉州城的西门吊桥，向西南可达岭南广东。" );

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
