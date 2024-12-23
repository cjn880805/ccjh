//baituoshan.h

//Sample for room:  白驼山
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShancity);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山");
	add_door("长安城", "长安城", "白驼山");
	add_door("昆仑山下", "昆仑山下", "白驼山");

	add_door("白驼山东街", "白驼山东街", "白驼山");

};

ROOM_END;
