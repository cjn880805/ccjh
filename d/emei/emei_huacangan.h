//huacangan.h
//Sample for room:  峨嵋华藏庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_huacangan);

virtual void create()			//Call it when Room Create
{
	set_name( "峨嵋华藏庵");
	add_npc("pub_nigu2");            // add by zdn  2001-07-14
	add_door("峨嵋金顶", "峨嵋金顶", "峨嵋华藏庵");
	add_door("峨嵋睹光台", "峨嵋睹光台", "峨嵋华藏庵");
//	add_door("峨嵋卧云庵", "峨嵋卧云庵", "峨嵋华藏庵");
	add_door("峨嵋华藏庵正殿", "峨嵋华藏庵正殿", "峨嵋华藏庵");

	set("long","华藏庵是金顶的主要建筑，规模宏大，中祀普贤菩萨，旁列万佛。华藏庵后边是睹光台，旁边是卧云庵。");

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
