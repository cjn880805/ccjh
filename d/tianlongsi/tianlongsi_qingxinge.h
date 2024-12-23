//qingxinge.h

//Sample for room:  天龙寺清心阁
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_qingxinge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺清心阁");

	add_npc("dali_xiaoshami");
				
	add_door("天龙寺无无境", "天龙寺无无境", "天龙寺清心阁");
	add_door("天龙寺兜率大士院", "天龙寺兜率大士院", "天龙寺清心阁");

   	
	set("sleep_room", 1);
    	set("no_fight",1);
    	set("no_steal",1);

/******************************************************************************

******************************************************************************/
};


ROOM_END;
