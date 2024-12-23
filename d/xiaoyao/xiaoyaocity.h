//xiaoyao.h

//Sample for room  逍遥林
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXiaoYaocity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林");


	add_door("逍遥林树林", "逍遥林树林", "逍遥林");

	add_door("木屋", "逍遥林木屋", "逍遥林");
	add_door("石屋", "逍遥林石屋", "逍遥林");
	add_door("酒家", "逍遥林酒家", "逍遥林");
	add_door("小屋", "逍遥林小屋", "逍遥林");
	add_door("小木屋", "逍遥林小木屋", "逍遥林");
	add_door("打铁屋", "逍遥林打铁屋", "逍遥林");
	add_door("工匠屋", "逍遥林工匠屋", "逍遥林");

};


ROOM_END;
