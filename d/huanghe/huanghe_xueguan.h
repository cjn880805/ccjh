//xueguan.h

//Sample for room: 黄河学馆
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_xueguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河学馆");

	//add npcs into the room
	add_npc("pub_xiucai");

	add_door("黄河古浪", "黄河古浪", "黄河学馆");

	set("long","一间简陋的私塾，四壁皆空，屋子中摆满了学生从自己家里抬来的方桌、长凳。一张书案放在屋子的一头，案上摆着几本翻开了的〖三字经〗、〖百家姓〗和一把戒尺。至圣先师孔老夫子的石刻拓片侧身像贴在书案的後面。");

/*****************************************************
	set("exits", ([
		"south"    : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));
//	
********************************************/
};


CHANGAN_END;
