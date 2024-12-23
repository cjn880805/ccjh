//yangzhoucity.h

//Sample for room:  扬州城
//coded by Fisho
//data: 2000-11-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRyangzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州城");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");

	add_door("扬州北门", "扬州北门", "扬州城");
	add_door("扬州东门", "扬州东门", "扬州城");
	add_door("扬州南门", "扬州南门", "扬州城");
	add_door("扬州西门", "扬州西门", "扬州城");

	add_door("扬州兵营", "扬州兵营", "扬州城");
	add_door("扬州当铺", "扬州当铺", "扬州城");
	add_door("扬州赌场", "扬州赌场", "扬州城");
	add_door("扬州客店", "扬州客店", "扬州城");
	add_door("扬州钱庄", "扬州钱庄", "扬州城");
	add_door("扬州书院", "扬州书院", "扬州城");
	add_door("扬州武馆", "扬州武馆", "扬州城");
	add_door("扬州武庙", "扬州武庙", "扬州城");
	add_door("扬州药铺", "扬州药铺", "扬州城");
	add_door("扬州杂货铺", "扬州杂货铺", "扬州城");
	add_door("扬州打铁铺", "扬州打铁铺", "扬州城");
	add_door("扬州丽春院", "扬州丽春院", "扬州城");
	add_door("扬州醉仙楼", "扬州醉仙楼", "扬州城");
	add_door("扬州衙门大门", "扬州衙门大门", "扬州城");
	add_door("扬州财主大门", "扬州财主大门", "扬州城");
	add_door("扬州春来茶馆", "扬州春来茶馆", "扬州城");

};


ROOM_END;
