//hsyuan4.h

//Sample for room: 和尚院四部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "和尚院四部");

	add_npc("shaolin_hui_xu");

	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺和尚院四部");
	add_door("少林寺和尚院五部", "少林寺和尚院五部", "少林寺和尚院四部");

	set("long", "这里是和尚院待客的地方，靠墙左右两侧摆着一溜太师椅。墙角一几，放着几个茶壶。有个茶壶壶身上题了“碧螺春”三个篆字，壶嘴热气腾腾，似乎是刚沏的新茶。一位小沙弥在一边垂手站立。" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"wuchang3",
		"west" : __DIR__"zhulin4",
		"south" : __DIR__"zoulang6",
		"north" : __DIR__"hsyuan5",
	]));
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
//	
********************************************/
};


ROOM_END;
