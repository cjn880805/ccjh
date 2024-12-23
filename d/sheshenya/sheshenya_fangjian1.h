//fangjian1.h

//Sample for room: 房间1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖房间1");


	add_door("舍身崖石洞", "舍身崖石洞", "舍身崖房间1");

	set("long","可以看出这里以前曾经是一个下棋的地方，房间除了一张石几，两只软椅之外，空荡荡的一无所有，石几上刻着纵横十九道棋路，棋局上布着二百多颗棋子，却是黑白对峙，竟然是一局没有下完的棋。");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
*****************************************************/
};


ROOM_END;
