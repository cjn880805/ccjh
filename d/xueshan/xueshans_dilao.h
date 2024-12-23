//dilao.h

//Sample for room: 地牢
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_dilao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺地牢");


	add_door("雪山寺", "雪山寺", "雪山寺地牢");

    set("long","这是一个阴暗、潮湿的牢房。你感到奇怪的是怎麽会不时听到一点怪声却怎么也找不到人呢? " );
    

/*****************************************************
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
********************************************/
};


ROOM_END;
