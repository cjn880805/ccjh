//dangpu.h

//Sample for room: 当铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "当铺");

	//add npcs into the room
	add_npc("pub_huangyu");/////////////////////////
	add_npc("xiangyang_qiuhang");        //add by zdn 2001-07-20
			

	add_door("襄阳西北", "襄阳西北", "襄阳当铺");

	set("long", "这是家远近闻名的当铺，三开间的门面，一块写着『邱航当铺』四个金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，你一进去就有一种压抑和悲怅的感觉，柜台后的老板邱航头也不抬的只顾拨拉着算盘，柜台上方挂着一块花木牌子(paizi) 。据街坊们说铁面当铺给的价还不算最坏，并且从不问货的来处，除了活人什么都收，所以生意很不错。" );
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : "你情我愿，概不赊欠。\n",
	]));
	set("exits", ([
		"north" : __DIR__"westjie1",
	]));
	set("objects", ([
		__DIR__"npc/qiuhang" : 1,
	]));
********************************************/
};


ROOM_END;
