//fangjuku.h

//Sample for room: 防具库
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fangjuku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "防具库");

	add_npc("shaolin_dao_xiang");

	add_door("少林寺武器库", "少林寺武器库", "少林寺防具库");
	add_door("少林寺药品库", "少林寺药品库", "少林寺防具库");

	set("long", "这是一间很大的房间，靠墙整齐地放着一个个大柜子，不少柜子门敞开着，露出里面的各种防具，品种之多，是你生平仅见。一位灰衣僧人正埋头整理一堆破损的护具。连你进来也没有注意。" );

/*****************************************************
	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
	]));
//	
********************************************/
};


ROOM_END;
