//shanjiao.h

//Sample for room:  白驼山山脚
//coded by zouwenbin
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRBaiTuoShan_shanjiao);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山山脚");

	
	add_door("白驼山", "白驼山", "白驼山山脚");

	add_door("山上", "白驼山山上", "白驼山山脚");
	add_door("坟地", "白驼山坟地", "白驼山山脚");
	add_door("树林", "白驼山树林", "白驼山山脚");
	add_door("酒店", "白驼山酒店", "白驼山山脚");
	add_door("农舍", "白驼山农舍", "白驼山山脚");
	add_door("打铁铺", "白驼山打铁铺", "白驼山山脚");
	add_door("山贼窝", "白驼山山贼窝", "白驼山山脚");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp