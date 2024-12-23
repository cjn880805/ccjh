//xiyu.h

//Sample for room: ����
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("monster_6k");      //add by zdn 2001-07-16
//	add_npc("kunlun_yulingzi");        //add by zdn 2001-07-20

	add_door("������", "������", "����");

	add_door("�����Į", "�����Į", "����");

};


XIYU_END;
