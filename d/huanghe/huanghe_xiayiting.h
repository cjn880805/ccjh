//xiayiting.h

//Sample for room: 侠义厅
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_xiayiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠义厅");
	
	add_npc("huanghe_zu");        //add by zdn 2001-07-20
	add_npc("pub_jiaoqi"); 

	add_door("黄河广场", "黄河广场", "黄河侠义厅");

	set("long","这是黄河帮议事的大厅，厅上挂着「侠义厅」三字匾额。厅里靠北朝南放着一张虎皮交椅，两边摆设着几副红木桌椅，非常有气派。墙上附庸风雅地挂了几幅丹青书法。(paizi)。");

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/sha" : 1,
		__DIR__"npc/peng" : 1,
		__DIR__"npc/liang" : 1,
	]));
//	
********************************************/
};


CHANGAN_END;
