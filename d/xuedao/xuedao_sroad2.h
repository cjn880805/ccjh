//sroad2.h

//Sample for room:  血刀门雪山路2
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门雪山路2");



	add_door("血刀门雪山路3", "血刀门雪山路3", "血刀门雪山路2");
	add_door("血刀门雪山路1", "血刀门雪山路1", "血刀门雪山路2");

	set("long","一条山路蜿蜒在山间。向西望去，可以见到大雪山的银色的雪顶在熠熠生辉。");
    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad1",
                "westup"    : __DIR__"sroad3",
        ]));
******************************************************************************/
};


ROOM_END;
