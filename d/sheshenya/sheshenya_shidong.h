//shidong.h

//Sample for room: 石洞
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_shidong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖石洞");


	add_door("舍身崖房间1", "舍身崖房间1", "舍身崖石洞");
	add_door("舍身崖房间2", "舍身崖房间2", "舍身崖石洞");
	add_door("舍身崖房间3", "舍身崖房间3", "舍身崖石洞");
	add_door("舍身崖石室1", "舍身崖石室1", "舍身崖石洞");
	add_door("舍身崖石室2", "舍身崖石室2", "舍身崖石洞");

	set("long","这是一个比较大的圆形石洞，光亮从左边的窗口透了过来，细看那窗的时候，发现原来是镶在石壁上的一块大水晶透过水晶向外看去，只见鱼虾水族来回游动，原来你竟处身水底之中！");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"shishi3",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));
*****************************************************/
};


ROOM_END;
