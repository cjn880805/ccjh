//shanjiao.h

//Sample for room:  ����ɽɽ��
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
	set_name( "����ɽɽ��");

	
	add_door("����ɽ", "����ɽ", "����ɽɽ��");

	add_door("ɽ��", "����ɽɽ��", "����ɽɽ��");
	add_door("�ص�", "����ɽ�ص�", "����ɽɽ��");
	add_door("����", "����ɽ����", "����ɽɽ��");
	add_door("�Ƶ�", "����ɽ�Ƶ�", "����ɽɽ��");
	add_door("ũ��", "����ɽũ��", "����ɽɽ��");
	add_door("������", "����ɽ������", "����ɽɽ��");
	add_door("ɽ����", "����ɽɽ����", "����ɽɽ��");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp