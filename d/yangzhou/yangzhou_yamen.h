//yamen.h

//Sample for room: 衙门大门
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_yamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衙门大门");

	//add npcs into the room

	add_npc("pub_yayi");
	add_npc("pub3_xunbu");
	
	add_door("扬州西北", "扬州西北", "扬州衙门大门");

	set("long", "这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前巡逻。(paizi)，柜台后坐着唐老板，一双精明的上上下下打量着你。据街坊们说铁面当铺给的价还不算最坏，并且从不问货的来处，除了活人什么都收，所以生意很不错。" );
/*****************************************************
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
		__DIR__"npc/xunbu" : 1,
	]));
********************************************/
};


ROOM_END;
