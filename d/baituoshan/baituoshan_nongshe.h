//nongshe.h

//Sample for room: 农舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_nongshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "农舍");

	//add npcs into the room
	add_npc("pub_woman");
	
	add_door("白驼山广场", "白驼山广场", "白驼山农舍");

	set("long", "这里是一间小农舍，家具很新。看来主人比较富裕。");

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
