//sheshengya.h

//Sample for room  …·…Ì—¬
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRSheShenYacity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "…·…Ì—¬");


};


ROOM_END;
