//houyuan.h

//Sample for room: 白驼山后院
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_houyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山后院");

	//add npcs into the room
	add_npc("pub_zhangma");
	
	add_door("白驼山竹园", "白驼山竹园", "白驼山后院");

	set("long", "这是僻静的后院，住着『欧阳克』的老奶妈『张妈』.由于年岁已高，她已经不干活了，在这里静养");

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
