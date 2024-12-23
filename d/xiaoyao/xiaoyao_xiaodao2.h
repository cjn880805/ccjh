//xiaodao2.h

//Sample for room: 小道2
//coded by zouwenbin
//data: 2000-11-17

/*
Edit by wolfman 2001-6-28
加入临时变量no_book，意在判断论语是否已被人拿走
*/

ROOM_BEGIN(CRXiaoYao_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林小道2");
	set_temp("no_book",1);

	add_npc("xiaoyao_goudu");
	add_npc("pub_likuozui");

	add_door("逍遥林小道1", "逍遥林小道1", "逍遥林小道2");
	add_door("逍遥林小道3", "逍遥林小道3", "逍遥林小道2");
	add_door("逍遥林木屋", "逍遥林木屋", "逍遥林小道2");
	add_door("逍遥林小木屋", "逍遥林小木屋", "逍遥林小道2");

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
