//munitang.h

//Sample for room:  天龙寺牟尼堂
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_munitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺牟尼堂");

	add_npc("dali_kurong");
	add_npc("dali_bencan");
	add_npc("dali_benxiang");
	add_npc("dali_benguan");
	add_npc("dali_benchen");
	add_npc("dali_benyin");
	
	set_temp("about_yyz",1);			
	add_door("天龙寺般若台", "天龙寺般若台", "天龙寺牟尼堂");

	set("long","这是高僧们的静修之处。整堂全以松木制成，板门木柱，木料均不去皮，天然质朴，和一路行来金碧辉煌的殿堂截然不同。室中五个和尚分坐五个蒲团。四僧朝外，东首一个和尚面朝里壁一动不动。");
    	

/******************************************************************************
        set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
		__DIR__"npc/kurong" : 1,
		__DIR__"npc/benguan" : 1,
		__DIR__"npc/benxiang" : 1,
		__DIR__"npc/bencan" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
