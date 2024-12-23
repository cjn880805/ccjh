//xiaolu.h

//Sample for room:  峨嵋小路
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋小路");

	add_npc("animal_dushe");
				
	add_door("峨嵋青石阶", "峨嵋青石阶", "峨嵋小路");
	add_door("武当三不管", "武当三不管", "峨嵋小路");
//	add_door("成都东府河桥", "成都东府河桥", "峨嵋小路");
//	add_door("成都东府河桥", "成都东府河桥", "峨嵋小路");

	set("long","这是四川与湖北的交界。一条静悄悄的小土路，两旁有疏疏落落的农舍耕田，但路上行人很少，都匆匆赶路。");

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
