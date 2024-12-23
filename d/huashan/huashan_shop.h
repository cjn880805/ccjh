//shop.h

//Sample for room: 山顶小店
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山顶小店");

	//add npcs into the room
	add_npc("pub_xiaoer2");

	add_door("华山练武场", "华山练武场", "华山山顶小店");

	set("long", "这里是华山山顶的一间小店，卖些简单的饮食，专门赚那些游客的钱。");  

/*****************************************************
	set("exits", ([
		"east" : __DIR__"square",
	]));
//	
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
