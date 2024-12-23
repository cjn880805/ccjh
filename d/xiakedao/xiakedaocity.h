//xiakedaocity.h

//Sample for room:  ���͵���̲
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRxiakedaocity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵���̲");
	
	add_npc("pub_yufu");        //add by zdn 2001-07-16


	add_door("���͵�ƽԭС·", "���͵�ƽԭС·", "���͵���̲");

	add_door("���͵�ʯ��", "���͵�ʯ��", "���͵���̲");

	set("long", "����������͵��ˡ�������һ���޼ʵĴ󺣣���������һƬ���֡����ϵĿ����ƺ��ǳ����ʣ���ʪ�ĺ����д���һ�ɻ��㣬���Ǻô��һƬɳ̲������ʯ����ͣ����ʮ���Ҵ�С�Ĵ�ֻ(boat)��" );
	

/********************************************************
 
****************************************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp 