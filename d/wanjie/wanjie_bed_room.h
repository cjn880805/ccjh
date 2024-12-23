//bed_room.h

//Sample for room: 卧室
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_bed_room);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "卧室");


	add_door("万劫谷小厅", "万劫谷小厅", "万劫谷卧室");

	set("long","这是钟谷主的卧室，室内大红的帏帐挂在大红的木床之上。墙上贴满了各种花花绿绿的东西。床边有个小柜，柜上放着一盏豆油灯。");
	
	set("sleep_room", 1);	//add by lanwood
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
