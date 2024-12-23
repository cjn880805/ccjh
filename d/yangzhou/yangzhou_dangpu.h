//dangpu.h

//Sample for room: 当铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "当铺");


	add_door("扬州东南", "扬州东南", "扬州当铺");

	set("long", "这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上摆着一个牌子(paizi)，柜台后坐着唐老板，一双精明的上上下下打量着你。据街坊们说铁面当铺给的价还不算最坏，并且从不问货的来处，除了活人什么都收，所以生意很不错。" );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
/*****************************************************
	set("item_desc", ([
		"paizi" : "公平交易\n
sell        卖 
buy         买
redeem      赎
value       估价
",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"up"   : __DIR__"xiaobaozhai",
	]));
********************************************/
};


ROOM_END;
