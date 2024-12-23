//yaocaidian.h

//Sample for room: 黄河皮货药材店
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_yaocaidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河皮货药材店");

	//add npcs into the room
	add_npc("pub_huoji");

	add_door("黄河古浪", "黄河古浪", "黄河皮货药材店");

	set("long","这是古浪城里唯一的一家店铺，一踏进铺内就可闻到一股淡淡的膻味，隐隐可以看见堆放在后院翻晒的各式皮货，怕有不下千余件。在西墙边，立了一个大红木药柜，里面盛放了草药。");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
********************************************/
};


CHANGAN_END;
