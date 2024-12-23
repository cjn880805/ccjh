//nianhuasi.h

//Sample for room: 拈花寺
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiWest_nianhuasi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "拈花寺");

	//add npcs into the room
	add_npc("pub_laojisi1");
	
	add_door("大理城山路2", "大理城山路2", "大理城拈花寺");

	set("long", "山路越走越荒僻，转过四个山坳，来到一座小小的古庙前，庙门上写着‘拈花寺’三字。佛教是大理国教。大理京城内外，大寺数十，小庙以百计，这座‘拈花寺’地处偏僻，无甚香火，即是世居大理之人，多半也不知晓。" );

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
