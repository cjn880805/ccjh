//yimen.h

//Sample for room: 燕子坞仪门
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_yimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞仪门");
	add_npc("murong_bo");        //add by zdn 2001-07-20
	

	add_door("燕子坞龙凤厅", "燕子坞龙凤厅", "燕子坞仪门");
	add_door("燕子坞参合居", "燕子坞参合居", "燕子坞仪门");
	add_door("燕子坞沁芳阁", "燕子坞沁芳阁", "燕子坞仪门");
	add_door("燕子坞啖糯厅", "燕子坞啖糯厅", "燕子坞仪门");

    set("long", "一扇朱漆的雕花大门，一块醒目的牌子挂于门上，上镌黑色小篆写的 '仪门' 二字，给人一种庄严威武的感觉。东面就是燕子坞门人休息的地方，向西则是慕容家人用饭的啖糯厅。" );
    
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