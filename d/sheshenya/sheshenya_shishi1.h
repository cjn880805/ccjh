//shishi1.h

//Sample for room: 石室1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_shishi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖石室1");



	add_door("舍身崖石洞", "舍身崖石洞", "舍身崖石室1");

	set("long","这是一个石头砌成的房间，因为好久没有人来过，散发着一些很难闻的气味，房间中到处可以看到蛛丝和虫迹。");

/*****************************************************
	set("exits", ([
		"east" : __DIR__"shiji1",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
