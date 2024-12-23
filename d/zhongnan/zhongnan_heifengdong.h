//heifengdong.h

//Sample for room: 终南山黑凤洞
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_heifengdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山黑凤洞");
	
	add_npc("pub_youke2");
	add_npc("pub_lady3");   //2001-07-10 zdn add

	add_door("终南山树林7", "终南山树林7", "终南山黑凤洞");

	set("long","此处位於终南山脉东部的太阳山上。只见山峰直上直下，像刀切般的陡峭，只山腰上有一个碾盘子粗的石洞，不时冒出一股黑气，怪可怕的。往西是一片树林。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "westup"  : __DIR__"shulin7",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
