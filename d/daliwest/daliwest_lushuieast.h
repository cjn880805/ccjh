//lushuieast.h

//Sample for room: 东泸水河谷
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_lushuieast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "东泸水河谷");

	add_npc("pub_shaonu");
	add_npc("pub_daoke");       // add by zdn 2001-0-13

	add_door("大理城碧罗雪山", "大理城碧罗雪山", "大理城东泸水河谷");
	add_door("大理城巴的甸", "大理城巴的甸", "大理城东泸水河谷");

	set("long", "西面这一大片河谷处在碧罗雪山和高黎山之间，由东泸水冲刷而成，地势低洼，因而气候较温暖，聚居了大量乌夷族人。乌夷先民沿河谷开发了一些梯田。四周山高林密，男子多从事狩猎。沿着脚下的向西直抵一个大镇子。" );
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
