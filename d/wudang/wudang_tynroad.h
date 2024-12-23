//tynroad.h

//Sample for room: 武当桃园小路
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tynroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当桃园小路");

	add_npc("wudang_shouyuan");

	add_door("武当", "武当", "武当桃园小路");
	add_door("武当", "武当", "武当桃园小路");

	set("long","眼前豁然开朗，你轻松地走在桃园边的小路上。路上落英缤纷，一边是桃树林，盛开着粉红的桃花，红云一片，望不到边。还可以看见蜜蜂「嗡嗡」地在花间飞上飞下忙个不停，间或传来猿猴的叽咋声。这儿是武当山脚，北边是条环山的黄土路。");
    

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"tyroad8",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
*****************************************************/
};


ROOM_END;
