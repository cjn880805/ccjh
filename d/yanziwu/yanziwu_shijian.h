//shijian.h

//Sample for room: 燕子坞试剑台
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shijian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞试剑台");

	add_door("燕子坞长廊", "燕子坞长廊", "燕子坞试剑台");

    set("long", "玉石栏杆围成的一座石台，慕容世家的弟子经常在此切磋武技，台角放着刀枪剑戟等十八般兵器。栏杆外水面上东一簇，西一簇的立着一些木桩(muzhuang)。" );
    
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