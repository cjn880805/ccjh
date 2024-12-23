//fhs.h

//Sample for room:  峨嵋伏虎寺
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_fhs);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋伏虎寺");

	add_npc("pub_girldizi");

	add_door("峨嵋密林1", "峨嵋密林1", "峨嵋伏虎寺");
	add_door("峨嵋密林2", "峨嵋密林2", "峨嵋伏虎寺");

	set("long","伏虎寺是入山第一大宝刹，隐伏在高大的乔木林间，四周楠木参天，多达十万余株。伏虎寺气象庄严，规模宏盛，殿堂宽敞，势度巍峨。寺刹虽掩覆于翠绿浓黛之中，但屋瓦却无一片落叶。出寺西上解脱坡便是观音堂。");
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
