//tieqiang.h

//Sample for room: 铁枪庙
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRJiaXing_tieqiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "铁枪庙");


	add_npc("pub_fanghenxiao");

	add_door("嘉兴城", "嘉兴城", "嘉兴铁枪庙");

	set("outdoors", "quanzhou");
/*****************************************************
	set("long", @LONG
这铁枪庙祀奉的是五代时名将铁枪王彦章。庙旁有座高塔，塔顶
群鸦世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢侵
犯，以致生养繁殖，越来越多。案桌下有个小洞(dong)。
LONG );
	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));
        set("item_desc", ([
	    "dong" : "一个在案桌下隐藏得很好的土洞。\n",
	]));
        set("objects", ([
		__DIR__"npc/wuya": 4
	]));
********************************************/
};


ROOM_END;




