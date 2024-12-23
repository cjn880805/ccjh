//guchangcheng.h

//Sample for room: 黄河古长城
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_guchangcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河古长城");

	//add npcs into the room
	add_npc("pub_menmian");

	add_door("黄河营盘水", "黄河营盘水", "黄河古长城");
	add_door("黄河石门", "黄河石门", "黄河古长城");
	add_door("黄河", "黄河", "黄河古长城");

	set("long","这里是一段古长城。相传是当年秦始皇派他的心腹爱将蒙恬率三十万大军所修。世事变迁、沧海桑田，如今这里已是一片废墟，唯一依稀可见的是夯土制成的烽火台象个小土包一样矗立在那里。黄河从西向东流去，河上有一叶小舟摆渡乘客，你可以叫(yell)一下船家。---呜---”声。");

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"yinpanshui",
		"southeast" : __DIR__"shimen",
	]));
	set("objects", ([
		__DIR__"npc/menmian" :1,
	]));
********************************************/
};


CHANGAN_END;
