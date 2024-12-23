//huandi2.h

//Sample for room: 荒路2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_huandi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "荒路2");
	
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");            // add by zdn 2001-07-13 

	set("monster_chance", 50);

	add_door("关外荒路1", "关外荒路1", "关外荒路2");
	add_door("关外山神庙", "关外山神庙", "关外荒路2");

    set("long","这是城东的一条荒路，路旁杂乱的长着齐膝的荒草，远近荒无一人。两旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒野上远远传去，一派凄凉的景象。" );
	

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
