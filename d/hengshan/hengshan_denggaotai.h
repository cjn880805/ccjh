//denggaotai.h

//Sample for room: 衡山登高台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_denggaotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山登高台");


	add_door("衡山南天门", "衡山南天门", "衡山登高台");

    set("long","这里是南天门登高望远的好去处。你站在这里，俯视诸峰，丘垤如泥丸。看湘江北去，九向九背，时隐时现。周围烟霞，碧罗，紫盖，天柱诸峰环抱，气象万千。" );
    

/*****************************************************
        set("exits", ([ 
           "northdown"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
