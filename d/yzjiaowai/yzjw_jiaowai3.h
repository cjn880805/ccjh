//yzjw_jiaowai3.h

//Sample for room:  ��������3
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
	set_name( "��������3");
	add_npc("pub_luidekuai");	
	
	add_door("��������4","��������4","��������3");
	add_door("��������2","��������2","��������3");
//	add_door("��������","��������","��������3");


    set("long","���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ�����в������֣�������ת��ʹ���ʱ���⾡����");

};


ROOM_END;
