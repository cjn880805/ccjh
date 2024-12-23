//damen.h

//Sample for room:  天龙寺大门
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺大门");



	add_door("大理城宏圣寺塔", "大理城宏圣寺塔", "天龙寺大门");
				
	add_door("天龙寺塔林", "天龙寺塔林", "天龙寺大门");

	set("long","你来到了天龙寺大门前，只见气势恢弘的两个大门柱上刻有一付对联( duilian )，红漆覆字，颇有点拨众生之意。抬头上望，门楣上一块黑木大匾，上题“崇圣寺”三个大字，笔意苍松。此乃正式寺名，但大理百性叫惯了，都称之为“天龙寺”。");

/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    心性无染本自圆成　但离妄缘即如如佛\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
******************************************************************************/
};


ROOM_END;