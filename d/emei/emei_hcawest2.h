//hcawest2.h
//Sample for room:  峨嵋华藏庵西廊2
//coded by zouwenbin
//data: 2000-11-30
ROOM_BEGIN(CREMei_hcawest2);
virtual void create()			//Call it when Room Create
{
	set_name( "峨嵋华藏庵西廊2");
	add_npc("emei_kong");	
	add_npc("emei_wenfang");	

	add_door("峨嵋华藏庵西廊1", "峨嵋华藏庵西廊1", "峨嵋华藏庵西廊2");
	add_door("峨嵋华藏庵禅房", "峨嵋华藏庵禅房", "峨嵋华藏庵西廊2");

	set("long","这里是峨嵋华藏庵西廊。走廊往南禅房，北边通往广场。");
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
