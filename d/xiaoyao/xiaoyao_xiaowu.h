//xiaowu.h

//Sample for room: С��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С��");


	add_door("��ң��С��3", "��ң��С��3", "��ң��С��");

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
