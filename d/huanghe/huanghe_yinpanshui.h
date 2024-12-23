//yinpanshui.h

//Sample for room: 黄河营盘水
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_yinpanshui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河营盘水");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-14


	add_door("黄河冰草湾", "黄河冰草湾", "黄河营盘水");
	add_door("黄河古长城", "黄河古长城", "黄河营盘水");

	set("long","这里是当年蒙恬修长城时驻军的地方，蒙恬治军有方，当年他亲自带人在驻地挖了好几口甜水井，使士卒们不用喝又苦又涩的咸水，后来此地的百姓们叫这里为营盘水，称这里的井为“蒙恬井”。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"bingcao",
		"northeast" : __DIR__"guchangcheng",
	]));
********************************************/
};


CHANGAN_END;
