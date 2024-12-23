//canheju.h

//Sample for room: 燕子坞参合居
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_canheju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞参合居");

	add_door("燕子坞仪门", "燕子坞仪门", "燕子坞参合居");
	add_door("燕子坞秋爽斋", "燕子坞秋爽斋", "燕子坞参合居");
	add_door("燕子坞缀锦楼", "燕子坞缀锦楼", "燕子坞参合居");
	add_door("燕子坞翰墨书屋", "燕子坞翰墨书屋", "燕子坞参合居");

    set("long", "这是慕容世家首脑人物日常起居之地，布置得华丽中不乏清雅，平实中透着高贵。楠木方桌，大太师椅，以及墙上的字画都透着一股非凡之气。" );
    
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