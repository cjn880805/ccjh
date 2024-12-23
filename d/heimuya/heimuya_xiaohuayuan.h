//xiaohuayuan.h

//Sample for room: 黑木崖小花园
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaohuayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖小花园");

    add_npc("zm_riyue");     

	add_door("黑木崖后厅", "黑木崖后厅", "黑木崖小花园");
	add_door("黑木崖小舍", "黑木崖小舍", "黑木崖小花园");

	set("long", "从昏暗的地道中出来，你发现自己竟是置身于一个极精致的小花园中，红梅绿竹，青松翠柏，布置得颇具匠心，往东去是一间精雅小舍。 ");
    

/*****************************************************
        set("exits", ([
            "south" : __DIR__"didao6",
            "enter" :__DIR__"xiaoshe",   
        ]));
        
********************************************/
};


ROOM_END;
