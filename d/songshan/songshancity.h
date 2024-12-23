//songshan.h

//Sample for room:  ��ɽ
//coded by zouwenbin
//data: 2000-11-14

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRSongShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-15

	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("����", "����", "����");
	add_door("������", "������", "����");

	add_door("��ɽ̫����", "��ɽ̫����", "����");


};


ROOM_END;
