//doushuai.h

//Sample for room:  天龙寺兜率大士院
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_doushuai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺兜率大士院");

	CBox * box = Add_Box();
	box->add_object("baixiang", 1);	
	box->set_name( "铁柜");	
				
	add_door("天龙寺斗母宫", "天龙寺斗母宫", "天龙寺兜率大士院");
	add_door("天龙寺三无宫", "天龙寺三无宫", "天龙寺兜率大士院");
	add_door("天龙寺清心阁", "天龙寺清心阁", "天龙寺兜率大士院");
	add_door("天龙寺般若台", "天龙寺般若台", "天龙寺兜率大士院");

	set("long","这是一般参拜者所能到的最远的地方，再往南就是天龙寺历代高僧静修之处——牟尼堂。那是常人不可轻易打搅的地方，你最好不要擅自闯入。除非你确信能给高僧们带去好消息。");
    
	set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);

/******************************************************************************
        set("exits", ([
                "north" : __DIR__"qingxinge",
		"south" : __DIR__"banruotai",
		"northeast" : __DIR__"doumugong",
		"northwest" : __DIR__"sanwugong",
	]));
	set("objects",([
                __DIR__"obj/xianglu" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
