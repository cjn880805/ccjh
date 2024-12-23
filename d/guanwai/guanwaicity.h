//guanwai.h

//Sample for room  ����
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRGuanWaicity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_mazei");      // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("��������ͷ", "��������ͷ", "����");
	add_door("����", "����", "����");
};


ROOM_END;
