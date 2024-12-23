//shuiyun.h

//Sample for room: 燕子坞水云轩
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shuiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞水云轩");

	add_door("燕子坞缀锦楼", "燕子坞缀锦楼", "燕子坞水云轩");

    set("long", "湖心的一座小小的亭台，四面环水，只有西侧有一条曲桥与岸上相连。轩中清风拂面，水波微扬，一群群游鱼清晰可见，别有一番诗情画意。" );
    
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