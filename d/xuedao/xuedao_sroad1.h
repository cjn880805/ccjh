//sroad1.h

//Sample for room:  血刀门雪山路1
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门雪山路1");



	add_door("血刀门雪山路2", "血刀门雪山路2", "血刀门雪山路1");
	add_door("成都南河桥", "成都南河桥", "血刀门雪山路1");

	set("long","川西多是崇山峻岭，交通不便。一条山路蜿蜒在山间，连接着藏边和中原。");
    

/******************************************************************************
        set("exits",([
                "north"  : "/d/city3/nanheqiaos",
                "westup" : __DIR__"sroad2",
        ]));
******************************************************************************/
};


ROOM_END;
