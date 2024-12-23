//pindi.h

//Sample for room: 燕子坞品笛庭
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_pindi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞品笛庭");

	add_door("燕子坞泊舟坞", "燕子坞泊舟坞", "燕子坞品笛庭");
	add_door("燕子坞龙凤厅", "燕子坞龙凤厅", "燕子坞品笛庭");

    set("long", "只见墙上挂有萧管之类的乐器，桌上放有一沓乐谱，想是慕容世家演练乐曲的所在了。在向西就到了太湖岸边，向东则是慕容世家接待宾客的龙凤厅了。" );
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