//caifang.h

//Sample for room: 柴房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_caifang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "柴房");

	set("monster_chance", 1);
	//add npcs into the room
//	add_npc("pub_laocai");
	
//	add_door("白驼山厨房", "白驼山厨房", "白驼山柴房");

	set("long", "这是间不宽的柴房，木柴已经快烧光了，墙角放着几把『柴刀』");

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
