//fangjian2.h

//Sample for room: 房间2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖房间2");


	add_door("舍身崖石洞", "舍身崖石洞", "舍身崖房间2");
	add_door("舍身崖地下石室1", "舍身崖地下石室1", "舍身崖房间2");

	set("long","这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的木头制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。");
	

/*****************************************************
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
*****************************************************/
};


ROOM_END;
