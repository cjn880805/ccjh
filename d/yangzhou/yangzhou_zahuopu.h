//zahuopu.h

//Sample for room: 杂货铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杂货铺");
	
	add_npc("pub_xiaoer2");         //add by zdn 2001-07-16


	add_door("扬州城", "扬州城", "扬州杂货铺");

	set("long", "这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。杨掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东西。摊上立着一块招牌(zhaopai)。" );
/*****************************************************
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"up"    : __DIR__"garments",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
********************************************/
};


ROOM_END;
