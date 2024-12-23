//wudang.h

//Sample for room  武当
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRWuDangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当");

	add_npc("helpnpc020");		//add by qzj 2001-08-13

	add_door("襄阳城", "襄阳城", "出口");
	add_door("佛山", "佛山", "出口");

    add_door("金殿", "武当金殿", "出口");
    add_door("桃园", "武当桃园", "出口");
    add_door("遇真宫", "武当遇真宫", "出口");
    add_door("小吃店", "武当小吃店", "出口");
    add_door("三清殿", "武当三清殿", "出口");
    add_door("南岩宫", "武当南岩宫", "出口");
    add_door("复真观", "武当复真观", "出口");



};


ROOM_END;
