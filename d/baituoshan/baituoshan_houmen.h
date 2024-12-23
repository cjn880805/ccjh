//houmen.h

//Sample for room: 白驼山后门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_houmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山后门");

	//add npcs into the room
	add_npc("pub_menwei");
	
	add_door("厨房", "白驼山厨房", "白驼山后门");

	set("long", "这是个山庄的后门。这里有捷径可以通向星宿海。");

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
