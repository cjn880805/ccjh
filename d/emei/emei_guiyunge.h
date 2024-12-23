//guiyunge.h

//Sample for room:  峨嵋归云阁
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_guiyunge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋归云阁");
	
	add_npc("pub_boydizi");
	add_npc("pub_girldizi");
	
	add_door("峨嵋观音堂", "峨嵋观音堂", "峨嵋归云阁");
	add_door("峨嵋玉女峰", "峨嵋玉女峰", "峨嵋归云阁");
	add_door("峨嵋纯阳殿", "峨嵋纯阳殿", "峨嵋归云阁");

	set("long","归云阁，原是唐代福昌达道禅师的道场。宋代绍兴年间，僧人士性又率众重建。归云阁左有玉女峰，西上可抵纯阳殿，东下是观音堂。");
    
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
