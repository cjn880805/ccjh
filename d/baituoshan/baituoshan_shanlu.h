//shanlu.h

//Sample for room: 白驼山山路
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shanlu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山山路");

	set("monster_chance", 1);

	add_door("白驼山广场", "白驼山广场", "白驼山山路");
	add_door("白驼山山路1", "白驼山山路1", "白驼山山路");

	set("long", "这里是山上的泥路。");
	set("no_clean_up", 0l);

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
