//bingying.h

//Sample for room: 兵营
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_bingying);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵营");

	//add npcs into the room
	add_npc("pub_shi");
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	
	add_door("扬州西南", "扬州西南", "扬州兵营");

	set("long", "这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。南边有一个门(men)。" );
/*****************************************************
	set("item_desc", ([
		"men" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 2,
	]));
//	
	create_door("south", "铁门", "north", DOOR_CLOSED);
********************************************/
};


ROOM_END;
