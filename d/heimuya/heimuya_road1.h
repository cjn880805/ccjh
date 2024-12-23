//road1.h

//Sample for room: 乱石坡
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "乱石坡");

	//add npcs into the room
	add_npc("animal_dushe");
	add_npc("pub_haoren");

	add_door("黑木崖林间小道", "黑木崖林间小道", "黑木崖乱石坡");

	add_door("黑木崖黄土路2", "黑木崖黄土路2", "黑木崖乱石坡");
	add_door("黑木崖黄土路4", "黑木崖黄土路4", "黑木崖乱石坡");

	set("long", "这是一处乱石怪异的小山岗，向东北是通往平安州的小路。据说前方经常有野兽出没，不可久留。");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
            "northeast" : __DIR__"road2",
            "southwest" : __DIR__"road4",
            "west"  : __DIR__"linjxd1",
            "east"  : __DIR__"dating4",
        ]));
********************************************/
};


ROOM_END;
