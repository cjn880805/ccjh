//lingjiu.h

//Sample for room: 灵鹫
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫");

	add_npc("helpnpc015");		//code by qzj 2001-08-13

	add_door("长安城", "长安城", "出口");

	add_door("灵鹫缥缈峰山脚", "灵鹫缥缈峰山脚", "出口");


/*****************************************************
 
********************************************/
};


ROOM_END;
