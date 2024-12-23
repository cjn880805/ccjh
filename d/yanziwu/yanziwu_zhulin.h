//zhulin.h

//Sample for room: 燕子坞竹林
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_zhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞竹林");
	
	add_npc("murong_deng");        //add by zdn 2001-07-20

	add_door("燕子坞翠霞堂", "燕子坞翠霞堂", "燕子坞竹林");
	add_door("燕子坞青冢", "燕子坞青冢", "燕子坞竹林");

    set("long", "凤尾森森，龙吟细细，竿竿青竹纵横交错，遮蔽天日。这里人迹罕至，微风拂过竹林，发出沙沙之声，你心中不免惴惴不安起来。林中一道道石子铺成的羊肠小道向前延伸。" );
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp