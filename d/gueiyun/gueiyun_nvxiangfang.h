//nvxiangfang.h

//Sample for room: 女厢房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_nvxiangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "女厢房");

	add_npc("guiyun_xiaolan"); 
	add_npc("guiyun_xiaoju");      // add by zdn 2001-07-14

	add_door("归云庄", "归云庄", "归云庄女厢房");

	set("long"," 这里是归云庄女弟子的休息室，摆着几张木床。床旁都有一支高脚架子，用来挂衣物。屋角一张几凳，放了一盆兰花，散着淡淡幽香。" );
	set("sleep_room",1);
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"huating",
	]));
********************************************/
};


ROOM_END;
