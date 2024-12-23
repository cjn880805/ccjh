//tianshanlu2.h

//Sample for room: ��ɽɽ·2
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_tianshanlu2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·2");
	
	add_npc("pub_xixiabing");          //add by zdn 2001-1-07-16

	add_door("������翷�ɽ��", "������翷�ɽ��", "������ɽɽ·2");
	add_door("���޺���ɽɽ·1", "���޺���ɽɽ·1", "������ɽɽ·2");
	add_door("������ɽɽ·1", "������ɽɽ·1", "������ɽɽ·2");

};


XIYU_END;
