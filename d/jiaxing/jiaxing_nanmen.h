//nanmen.h

//Sample for room: 嘉兴南门
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRJiaXing_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嘉兴南门");
	
	add_npc("pub_playboy");  // add by zdn 2001-07-14
	add_npc("pub_liufeiyan");

	set("resident", "嘉兴");

	add_door("嘉兴城", "嘉兴城", "嘉兴南门");
	add_door("泉州山路2", "泉州山路2", "嘉兴南门");
	add_door("桃花岛", "桃花岛", "嘉兴南门");


	

/*****************************************************
	set("long", @LONG
这里是嘉兴的南门。周围长着茂密的竹林。东面是座庙宇。
向南可入福建。向东南就是号称天堂的杭州城了。
LONG );
	set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
		"southeast": "/d/hangzhou/road1",
	]));
 ********************************************/
};


RESIDENT_END;




