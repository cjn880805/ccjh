//nanxiangfang.h

//Sample for room: 男厢房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_nanxiangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "男厢房");
	
	add_npc("pub_puren");         //add by zdn 2001-07-13
	add_npc("pub_liufuming"); 

	add_door("归云庄", "归云庄", "归云庄男厢房");

	set("long","这里是归云庄男弟子的休息室，摆着几张木床。床旁都有一支高脚架子，用来挂衣物。西首一扇小窗。外面是花园。" );
	set("sleep_room",1);
	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"huating",
	]));
********************************************/
};


ROOM_END;
