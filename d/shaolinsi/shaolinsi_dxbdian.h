//dxbdian.h

//Sample for room: 大雄宝殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dxbdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大雄宝殿");

	//add npcs into the room
	add_npc("shaolin_dao_zheng");/////////////////////////

	add_door("少林寺精进场", "少林寺精进场", "少林寺大雄宝殿");



	set("valid_startroom",1);
	set("book_count",1);

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"guangchang2",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	
********************************************/
};


ROOM_END;
