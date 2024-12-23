//road4.h

//Sample for room: 黄土路4
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路4");
	
        add_npc("pub_punk");       //add by zdn 2001-07-20

	add_door("黑木崖乱石坡", "黑木崖乱石坡", "黑木崖黄土路4");
	add_door("黑木崖龙门渡口", "黑木崖龙门渡口", "黑木崖黄土路4");

	set("long", "你走在一条黄土路上。这里是山西地界，往东就进入河北了。现在这里不是太平时节，还是快点走吧。");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"dukou1",
        ]));
********************************************/
};


ROOM_END;
