//tingxiang.h

//Sample for room: 燕子坞听香水榭
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_tingxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞听香水榭");
	
	add_npc("murong_youcao");        //add by zdn 2001-07-20

	add_door("燕子坞啖糯厅", "燕子坞啖糯厅", "燕子坞听香水榭");

    set("long", "绿柳杏花丛中有八九间茅房，四周竹篱掩映，错落有致，这就是慕容公子的婢女阿朱的住所了。" );
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