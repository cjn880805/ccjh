//qiushuan.h

//Sample for room: 燕子坞秋爽斋
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qiushuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞秋爽斋");

	add_door("燕子坞参合居", "燕子坞参合居", "燕子坞秋爽斋");

    set("long", "素幔低垂，设备朴素，临窗的桌上堆满卷轴，一大桶毛笔显示出主人学识渊博。一只剑形花瓶插着几朵犁花，带来几分清新的气息。" );
	
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