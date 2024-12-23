//bingying3.h

//Sample for room: 南兵营
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_bingying3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "南兵营");

	//add npcs into the room
	add_npc("pub_zuo");
	add_npc("pub_pian");
	add_npc("pub_bing");

	add_door("襄阳西南", "襄阳西南", "襄阳南兵营");

	set("long", "这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视着四周。看到你进来，他们全都向你瞪大眼睛盯着你。" );
/*****************************************************
	set("exits", ([		"east" : __DIR__"southjie3",	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
********************************************/
};


ROOM_END;
