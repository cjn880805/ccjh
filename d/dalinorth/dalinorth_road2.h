//road2.h

//Sample for room: 大理城官道2
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城官道2");

	set("resident", "南诏");

	add_npc("pub_playboy");
	add_npc("pub_daoke");     // add by zdn 2001-07-13

	add_door("大理城官道3", "大理城官道3", "大理城官道2");
	add_door("大理城官道1", "大理城官道1", "大理城官道2");

	set("long", "脚下崎岖的土路穿越川南的山区连接南北，这里已经进入云贵，横断山脉延绵耸立，乃是一道天然屏障隔绝南昭和蜀中。继续向西南穿过山区，可达大理，北去下山即是天府之国。道路两旁都是一望无际的崇山峻岭(mountain)，和联绵不绝的大森林(forest)。--峨嵋山。");
	
};


RESIDENT_END;
