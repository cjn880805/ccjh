//fushouan.h

//Sample for room:  峨嵋福寿庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_fushouan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋福寿庵");

	add_npc("pub_girldizi");
	add_npc("emei_zhen");
	

	add_door("峨嵋神水庵", "峨嵋神水庵", "峨嵋福寿庵");
	add_door("峨嵋灵文阁", "峨嵋灵文阁", "峨嵋福寿庵");

	set("long","福寿庵在神水庵南，是一个名叫天性的僧人建造的。庵前有九曲渠、流杯池，古人曾据在此饮酒流杯，观景赋诗，歌咏兴叹，不知夕日。庵旁有株大海棠树，数百苍龄，高达十余丈。");
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
