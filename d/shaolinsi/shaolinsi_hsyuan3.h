//hsyuan3.h

//Sample for room: 和尚院三部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "和尚院三部");
	set("sleep_room",1);

	add_npc("shaolin_hui_se");

	add_door("少林寺和尚院二部", "少林寺和尚院二部", "少林寺和尚院三部");

	set("long", "这里是僧众们饮食起居的地方。靠墙一溜摆着几张木床，床上铺的是篾席。床头叠着床薄被，冬天想必很冷，僧侣们全靠扎实的内功根基御寒。地上整齐的放着几个蒲团和木鱼。" );

/*****************************************************
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"zhulin2",
		"south" : __DIR__"hsyuan1",
		"north" : __DIR__"hsyuan3",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-xiu" : 1,
	]));
//	
********************************************/
};


ROOM_END;
