//shaolinsi.h

//Sample for room:  ������
//coded by zouwenbin
//data: 2000-11-14

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRShaoLinSicity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("shaolin_sengbing3");       //add by zdn 2001-07-20
	add_npc("helpnpc019");		//add by qzj 2001-08-13

	add_door("������ɽ�ŵ�", "������ɽ�ŵ�", "����");

};

ROOM_END;
