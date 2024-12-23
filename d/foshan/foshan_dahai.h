//dahai.h
//Sample for room: 佛山大海
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山南门");
	//add npcs into the room
	add_npc("pub_puren");
	add_door("佛山", "佛山", "佛山大海");
	add_door("侠客岛海滩", "侠客岛海滩", "佛山大海");

	set("long", "这里是佛山镇的南门。出南门向南，就到达南海之滨了。北面一条东西向的大街是佛山镇的主要街道。" );

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
