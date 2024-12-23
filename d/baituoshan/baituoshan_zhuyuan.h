//zhuyuan.h

//Sample for room: 白驼山竹园
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_zhuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山竹园");

	add_door("白驼山花园", "白驼山花园", "白驼山竹园");
	add_door("白驼山兔苑", "白驼山兔苑", "白驼山竹园");
	add_door("白驼山后院", "白驼山后院", "白驼山竹园");

	set("long", "这里是一个幽静的竹园，高高低低的翠竹把这里装点得别有情致。西北方是后院，东北方有个兔苑。南边是花园。.由于年岁已高，她已经不干活了，在这里静养");
	
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
