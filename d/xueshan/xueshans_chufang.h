//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺厨房");


	add_door("雪山寺", "雪山寺", "雪山寺厨房");

    
    set_temp("times" , 5);      
    set("no_fight",1);
    set("no_steal",1);

/*****************************************************
        set("item_desc",([
                "paizi" : "本厨房招收杂工。工作(work)一次付银十两。\n",
        ]));
        set("exits",([
                "south" : __DIR__"xiaoyuan",
        ]));
********************************************/
};


ROOM_END;
