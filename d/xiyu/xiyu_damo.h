//damo.h

//Sample for room: ��Į
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_damo);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Į");

//	add_npc("xiyu_lhz");
//	add_npc("kunlun_hetaichong");        //add by zdn 2001-07-20
	add_npc("pub_gongtianlai");

	add_door("����˿��֮·1", "����˿��֮·1", "�����Į");
	add_door("����ɽ���", "����ɽ���", "�����Į");

};


XIYU_END;
