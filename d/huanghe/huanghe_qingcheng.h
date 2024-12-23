//qingcheng.h

//Sample for room: 黄河青城
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_qingcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河青城");
	
	add_npc("pub_jianke");
	add_npc("pub_poorman");         //add by zdn 2001-07-14


	add_door("黄河河套", "黄河河套", "黄河青城");

	set("long","青城位于靖远以南三百二十里，西南八十里就是兰州，名为青城，其实只是个小镇，因为地处北去西夏的要冲，许多往来西夏和大宋的商旅都必须经过这儿，人来人往很是热闹。(skulls)。");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"shamo",
		"east"  : __DIR__"hetao",
	]));
********************************************/
};


CHANGAN_END;
