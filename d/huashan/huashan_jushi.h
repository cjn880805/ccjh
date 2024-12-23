//jushi.h

//Sample for room: 华山居室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_jushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "居室");
	set_temp("have_book",1);

	add_npc("huashan_yue_wife");

	add_door("华山长廊", "华山长廊", "华山居室");

};


ROOM_END;
