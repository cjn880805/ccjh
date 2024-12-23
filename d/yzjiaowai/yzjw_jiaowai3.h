//yzjw_jiaowai3.h

//Sample for room:  扬州树林3
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州树林3");
	add_npc("pub_luidekuai");	
	
	add_door("扬州密林4","扬州密林4","扬州树林3");
	add_door("扬州树林2","扬州树林2","扬州树林3");
//	add_door("扬州树林","扬州树林","扬州树林3");


    set("long","扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤随远。林中蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。");

};


ROOM_END;
