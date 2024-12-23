//qzroad4.h

//Sample for room: 泉州山路4
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州山路4");
	
	set("resident", "泉州");

	add_npc("pub_xiaozei");      //add by zdn 2001-07-14


	add_door("泉州山路5", "泉州山路5", "泉州山路4");
	add_door("泉州山路3", "泉州山路3", "泉州山路4");
	add_door("泉州莆仙平原", "泉州莆仙平原", "泉州山路4");


	set("long", "你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。北面是江南名城嘉兴。向南则进入福建武夷山区。东面有一个供路人休息的小茶亭。" );
	
	
/*****************************************************
	set("exits", ([
                "north"   : __DIR__"jxnanmen",
                "west"    : __DIR__"qzroad3",
//		"southup" : __DIR__"qzroad5",
		"southup" : "/d/fuzhou/fzroad1",
		"east"    : __DIR__"chating",
	]));
********************************************/
};


RESIDENT_END;
