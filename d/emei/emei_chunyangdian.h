//chunyangdian.h

//Sample for room:  峨嵋纯阳殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_chunyangdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋纯阳殿");
	
	add_npc("pub_nigu2");           // add by zdn 2001-07-14

	add_door("峨嵋归云阁", "峨嵋归云阁", "峨嵋纯阳殿");
	add_door("峨嵋神水庵", "峨嵋神水庵", "峨嵋纯阳殿");

	set("long","纯阳殿海拔一千余米，四面古木苍翠，幽静宜人。殿前有一石，叫普贤石，据说普贤菩萨登山时曾坐在这里休息过。在此可纵观峨嵋诸峰，仰望金顶，悬崖峭壁，离天咫尺。这里西上至神水庵，东下是归云阁。");
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
