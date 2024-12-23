//shanlu4.h

//Sample for room: 山路4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路4");

	//add npcs into the room
	add_npc("pub_shennongdizi");
	
	add_door("大理城山路5", "大理城山路5", "大理城山路4");
	add_door("大理城山路2", "大理城山路2", "大理城山路4");

	set("long", "一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两旁间或可见一些夷族的村镇。山路向南蜿蜒着。" );

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
