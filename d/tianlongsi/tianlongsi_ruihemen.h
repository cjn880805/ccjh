//ruihemen.h

//Sample for room:  天龙寺瑞鹤门
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_ruihemen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺瑞鹤门");


				
	add_door("天龙寺无我阁", "天龙寺无我阁", "天龙寺瑞鹤门");
	add_door("天龙寺无常阁", "天龙寺无常阁", "天龙寺瑞鹤门");

	set("long","这是通往天龙寺后寺的门户。你低头看看地上，只见铜门槛早已被踩踏得锃亮，足见此寺香火之盛了。抬头向南可以望见点苍山耸立云天。");
    

/******************************************************************************
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuchangge",
		"north": __DIR__"wuwoge",
	]));
******************************************************************************/
};


ROOM_END;
