//ximen.h

//Sample for room:  扬州西门
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_ximen);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州西门");

	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("mingjiao_fenggongying");
	add_npc("pub_xixuxi");

	add_door("扬州西南","扬州西南","扬州西门");
	add_door("扬州西门大道","扬州西门大道","扬州西门");
	add_door("扬州桃花林","扬州桃花林","扬州西门");

    set("long","这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告示(gaoshi)。    这里是罪犯逃往西域的必经之地，官兵们戒备森严，动不动就截住行人盘问。一条笔直的青石板大道向东西两边延伸。西边是郊外，骑马的、座轿的、走路的，行人匆匆。东边是城里。往北是一片桃林。");

/********************************************************
        set("outdoors", "city");
//	
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"north" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/d/mingjiao/npc/fenggongying" : 1,
        ]));
********************************************************/
 
};


ROOM_END;
