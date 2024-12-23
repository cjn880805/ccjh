//huayanding.h

//Sample for room:  峨嵋华严顶
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_huayanding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华严顶");

	add_npc("pub_girldizi");
	add_npc("emei_li");
				
	add_door("峨嵋十二盘4", "峨嵋十二盘4", "峨嵋华严顶");
	add_door("峨嵋莲花石", "峨嵋莲花石", "峨嵋华严顶");

	set("long","华严顶挺拔高峭，古刹云深，殿宇孤耸，风景奇险。这里视野开阔，仰可见金顶巍巍，俯可望群峰罗列，许多蹲伏山间的寺院也在眼底。由此向西过数坡，即到莲花石，东下过十二盘可到万年寺。北面是一间马厩。");

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
