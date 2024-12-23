//shanlu1.h

//Sample for room: 大理城川西山路
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城川西山路");

	set("resident", "乌弄城");

	add_npc("pub_playboy");
	add_npc("lj_shangtugong");	//川西碧磷洞商土公
	add_npc("pub_liumang");   // add by zdn 2001-07-13

	add_door("大理城乌弄城", "大理城乌弄城", "大理城川西山路");
	add_door("大理城剑川山口", "大理城剑川山口", "大理城川西山路");

	set("long", "你走在川西山间的一条土路上。此间属古蜀国境内，地势甚高，可山势相对较平缓。西面可见白雪皑皑的青藏高原群山，向南一路穿越山陵直通向云南大理。附近山间有些乌夷人的村落。");
	
};

RESIDENT_END;
