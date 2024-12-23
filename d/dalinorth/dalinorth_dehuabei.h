//dehuabei.h

//Sample for room: 大理城南诏德化碑
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_dehuabei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城南诏德化碑");

	set("resident", "南诏");

	add_npc("pub_youke");
	add_npc("pub_cunfu");   // add by zdn 2001-07-13

	add_door("大理城太和城", "大理城太和城", "大理城南诏德化碑");
	add_door("大理城官道3", "大理城官道3", "大理城南诏德化碑");

	set("long", "南诏阁逻风于大唐天宝年间，同大唐两次交战，歼唐军十六万。过后，阁逻风有悔意，为一时交恶，“岂顾前非，而忘大礼”。于是，派人收拾唐军阵亡将士，“祭而葬之，以存恩旧”，同时，令人撰文，详记天宝战争的近因和结果，表达不得已而叛唐的苦衷，将它刻成巨碑，于天宝十一年立于王都太和城国门外。。");
	
};


RESIDENT_END;
