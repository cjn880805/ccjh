//yzjw_nanmen.h

//Sample for room:  扬州南门
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州南门");

	add_npc("pub_bing");         //add by zdn 2001-07-16
	add_npc("pub_weiyangyu");
	add_npc("pub_lanlanglang");

	add_door("扬州西南","扬州西南","扬州南门");
	add_door("扬州草地7","扬州草地7","扬州南门");
	add_door("扬州草地8","扬州草地8","扬州南门");


	set("long","这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，官府的告示(gaoshi)因此不太显目。官兵们被近处的欢声笑语所吸引，似乎不是很认真在执勤。一条笔直的青石板大道向南北两边延伸。");

};


ROOM_END;
