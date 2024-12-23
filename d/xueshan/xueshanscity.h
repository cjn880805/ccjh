//xueshan.h

//Sample for room  雪山寺
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山寺");

	add_npc("xueshan_gelunbu");
	add_npc("zm_xueshan");

	add_door("血刀门雪山北麓", "血刀门雪山北麓", "雪山寺");

	add_door("雪山寺厨房", "雪山寺厨房", "雪山寺");
	add_door("雪山寺地牢", "雪山寺地牢", "雪山寺");
	add_door("雪山寺大殿", "雪山寺大殿", "雪山寺");
	add_door("雪山寺库房", "雪山寺库房", "雪山寺");

};


ROOM_END;
