//qingzong.h

//Sample for room: 燕子坞青冢
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qingzong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞青冢");

	add_door("燕子坞竹林", "燕子坞竹林", "燕子坞青冢");

    set("long", "你在竹林中七绕八绕，忽然豁然开朗，原来到了慕容世家的墓地，据说燕子坞的主人就葬于此了。地上长满了细的小草，传说这种草常年碧绿，永不枯萎。似乎除了向南有一片竹林外别无出口。" );
    
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