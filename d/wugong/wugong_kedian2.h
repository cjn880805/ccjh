//kedian2.h

//Sample for room: �书�͵��¥
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_kedian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书�͵��¥");


	add_door("�书�͵�", "�书�͵�", "�书�͵��¥");

    set("sleep_room", "1");
    set("no_fight", "1");
    set("hotel",1);
    

/*****************************************************
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);
        
        set("exits", ([
                "down" : __DIR__"kedian1",
        ]));
********************************************/
};


WUGONG_END;
