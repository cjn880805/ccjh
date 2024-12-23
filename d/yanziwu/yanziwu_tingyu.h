//tingyu.h

//Sample for room: 燕子坞听雨居
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_tingyu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞听雨居");
	
	add_npc("murong_bao");        //add by zdn 2001-07-20

	add_door("燕子坞小径", "燕子坞小径", "燕子坞听雨居");

    set("long", "这个小居建在湖上，看上去没有什么特别之处。四面为水，湖上烟波尽收眼底。唯一奇怪的是这儿放着一具瑶琴(qin)。" );
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