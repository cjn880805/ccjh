//xxroad4.h

//Sample for room: 星宿海小路
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xxroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海小路");

	add_npc("xingxiu_chuchen");	

	add_door("星宿海山间平地", "星宿海山间平地", "星宿海小路");
	add_door("星宿派储藏室", "星宿派储藏室", "星宿海小路");
	add_door("星宿海天山山路3", "星宿海天山山路3", "星宿海小路");
	
    set("long","山势在这里渐渐变得平缓，你已经可以听见西边山涧底的水声。东面有一个山洞。" );

/*****************************************************
        set("exits", ([
            "south" : __DIR__"xxroad4",
            "enter" : __DIR__"cangku",
            "north" : __DIR__"xxroad6",
        ]));
        set("objects", ([
            CLASS_D("xingxiu")+"/chuchen" : 1,
        ]) );
********************************************/
};


ROOM_END;
