//fangjian3.h

//Sample for room: 房间3
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖房间3");


	add_door("舍身崖石洞", "舍身崖石洞", "舍身崖房间3");

	set("long","你只觉得眼前陡然一亮，一个宫装的美女，正拿着一把长剑，对准了你的胸膛！。。。。一场虚惊之后，你才发现原来只是个白玉雕成的玉像，但是看上去却与真人一般无异。玉像的一双眸子莹然有光，神采飞扬。你此时只觉得神驰目眩，竟如着魔中邪，眼光再也离不开玉像。。。。");
	set("book_count",1);

/*****************************************************
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
