//jlyuan.h

//Sample for room: 戒律院
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_jlyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "戒律院");

	add_npc("shaolin_xuan_tong");
	add_npc("shaolin_qing_yuan");

	add_door("少林寺勤修场", "少林寺勤修场", "少林寺戒律院");

	set("no_fight", "1");

/*****************************************************

	set("exits", ([
		"southdown" : __DIR__"guangchang3",
	]));
	set("valid_startroom",1);
	set("objects",([
		CLASS_D("shaolin") + "/xuan-tong" : 1,
		__DIR__"npc/seng-bing2" : 3,
		__DIR__"npc/xiao-tong" : 1
	]));
//	
********************************************/
};


ROOM_END;
