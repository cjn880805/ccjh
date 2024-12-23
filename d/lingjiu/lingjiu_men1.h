//men1.h

//Sample for room: ¡È’«Ù “¥Û√≈
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_men1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "¡È’«Ù “¥Û√≈");

	//add npcs into the room
	add_npc("lingjiu_jujian");/////////////////////////

	add_door("¡È’ª≠¿»11", "¡È’ª≠¿»11", "¡È’«Ù “¥Û√≈");


    	set_temp("lock",1);

/*****************************************************
        set("exits", ([
		"west" : __DIR__"qiushi",
		"east" : __DIR__"changl11",
        ]));

	set("objects",([
                __DIR__"npc/jujian" : 1,
	]));
	set("item_desc", ([
	    "door" : (: look_door :),
        ]));

********************************************/
};


ROOM_END;
