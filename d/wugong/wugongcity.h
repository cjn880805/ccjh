//wugongcity.h

//Sample for room:  �书
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro WUGONG_BEGIN(room_name) to declare room
//and use macro WUGONG_END end declare
WUGONG_BEGIN(CRWuGongcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书");

	add_npc("pub_playboy");

	add_door("������ٵ�2", "������ٵ�2", "�书");

	add_door("�书������", "�书������", "�书");
	add_door("�书���2", "�书���2", "�书");
	add_door("�书���1", "�书���1", "�书");
	add_door("�书��¥", "�书��¥", "�书");
	add_door("�书���Ҵ���", "�书���Ҵ���", "�书");
	add_door("�书�͵�", "�书�͵�", "�书");
/********************************************************
 
****************************************************************/
};


WUGONG_END;
