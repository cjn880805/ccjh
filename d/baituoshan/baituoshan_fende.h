//fende.h

//Sample for room: 白驼山坟地
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_fende);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山坟地");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("pub_guafu");
	
	add_door("白驼山小路1", "白驼山小路1", "白驼山坟地");

	set("long", "这里是荒凉阴森的荒坟地。");

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
