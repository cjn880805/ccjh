//hcaeast2.h

//Sample for room:  峨嵋华藏庵东廊2
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaeast2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵东廊2");
	
	add_npc("pub_boydizi");        // add by zdn 2001-07-14

	add_door("峨嵋华藏庵东廊1", "峨嵋华藏庵东廊1", "峨嵋华藏庵东廊2");
	add_door("峨嵋华藏庵斋堂", "峨嵋华藏庵斋堂", "峨嵋华藏庵东廊2");

	set("long","这里是峨嵋华藏庵东廊。走廊往南通往斋堂，北边通往广场。");
    
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
