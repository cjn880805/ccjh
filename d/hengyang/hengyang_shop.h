//shop.h

//Sample for room: 小店
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小店");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	add_npc("pub3_xiejian");

	add_door("衡阳城", "衡阳城", "衡阳小店");

/*****************************************************
	set("long", "这里是衡阳县城的一间小店，卖些简单的饮食，专门赚那些游客的钱。 " );
 	set("exits", ([
		"north" : __DIR__"hengyang1",
		"up"    : __DIR__"huiyan",
	]));
	set("objects", ([
	      __DIR__"npc/xiaoer2" : 1,
	]));

********************************************/
};


ROOM_END;
