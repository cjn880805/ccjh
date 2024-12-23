//hsroad3.h

//Sample for room: 衡山黄土路
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_hsroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山黄土路");
	
	add_npc("pub_jianke");        //add by zdn 2001-07-20
	add_npc("pub_lushen");

	add_door("衡阳城", "衡阳城", "衡山黄土路");
	add_door("衡山棂星门", "衡山棂星门", "衡山黄土路");
	add_door("佛山南岭山口", "佛山南岭山口", "衡山黄土路");
	add_door("福州闽中大道", "福州闽中大道", "衡山黄土路");

    set("long","你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西面不远就是衡阳县城了。" );
    

/*****************************************************
    set("outdoors", "henshan");
	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));
********************************************/
};


ROOM_END;
