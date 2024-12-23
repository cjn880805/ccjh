//tianxiangting.h

//Sample for room: 天香堂大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_tianxiangting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天香堂大厅");

        add_npc("heimuya_xiang");              // add by zdn 2001-07-20


	add_door("黑木崖", "黑木崖", "黑木崖天香堂大厅");
	add_door("黑木崖天香堂", "黑木崖天香堂", "黑木崖天香堂大厅");

	set("long", "这是『日月神教』下第四大堂：天香堂的大厅，远远望去郁郁渺渺，好似不食人间烟火。堂梁上有一块匾(bian)。");
    

/*****************************************************
        set("exits", ([
                "west" : __DIR__"road1",
                "southup" : __DIR__"tian1",
        ]));
        set("item_desc", ([
            "bian": "上面写到：天香堂---日月神教圣姑住地。\n",
       	]) );
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp