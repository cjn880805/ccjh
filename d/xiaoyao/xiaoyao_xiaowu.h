//xiaowu.h

//Sample for room: 小屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小屋");


	add_door("逍遥林小道3", "逍遥林小道3", "逍遥林小屋");

    set("no_fight",1);
    set("no_steal",1);
    set("sleep_room",1);
	

/*****************************************************
        set("exits", ([ 
		"east" : __DIR__"xiaodao2", 
	]));
********************************************/
};


ROOM_END;
