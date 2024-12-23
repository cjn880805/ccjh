//fendi.h

//Sample for room: 坟地
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_fendi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "坟地");

	//add npcs into the room
	add_npc("pub_guafu");
	set("monster_chance", 1);
	
	add_door("白驼山山脚", "白驼山山脚", "白驼山坟地");

	set("long", "这里是荒凉阴森的荒坟地。");
    
    set_temp("times" , 1);

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
//last, register the room into ../server/RoomSetup.cpp