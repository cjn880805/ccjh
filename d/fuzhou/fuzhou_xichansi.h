//xichansi.h

//Sample for room: 西禅寺
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xichansi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "西禅寺");

	//add npcs into the room
	add_npc("pub_guest");
	add_npc("pub_kongchan");
	
	add_door("福州西", "福州西", "福州西禅寺");

    set("long", "西禅寺始建于梁朝，寺中玉佛楼玉佛为整玉雕就，宝相庄严，从来香火不绝。香客往来，但有所求，多得灵验。" );
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
