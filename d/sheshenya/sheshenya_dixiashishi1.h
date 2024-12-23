//dixiashishi1.h

//Sample for room: 地下石室1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_dixiashishi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖地下石室1");


	add_door("舍身崖房间2", "舍身崖房间2", "舍身崖地下石室1");
	add_door("舍身崖地下石室2", "舍身崖地下石室2", "舍身崖地下石室1");

	set("long","这是一个地下的秘密石室，四面可以感觉得到的只有强烈的杀气，以及处身地底的一些难闻的气味。在微弱的灯光下，你竟然看到有个人站着那里。继续往下好象还有路。");

/*****************************************************
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
		__DIR__"npc/qingyun" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
