//yaopinku.h

//Sample for room: 药品库
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_yaopinku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药品库");

	add_npc("shaolin_dao_xiang2");

	add_door("少林寺防具库", "少林寺防具库", "少林寺药品库");

	set("long", "这里是全寺僧侣领用药品的地方。房间里弭漫着股浓浓的药味。靠墙是一排排高及房顶的药柜，每个药柜都由上百个装药的小抽屉，上面贴满了密密麻麻的各种草头药名。东首墙边放着个巨大的暗红色杉木药柜，上面贴着个盖有方丈印签的大封条。一位中年僧人正来回忙碌着称量药品，熬药煎汤。" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));
//	
********************************************/
};


ROOM_END;
