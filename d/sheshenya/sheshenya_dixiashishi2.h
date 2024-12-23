//dixiashishi2.h

//Sample for room: 地下石室2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_dixiashishi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖地下石室2");

	add_npc("pub_qingyun");/////////////////////////

	add_door("舍身崖地下石室1", "舍身崖地下石室1", "舍身崖地下石室2");

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
