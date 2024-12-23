//huashancity.h

//Sample for room: ��ɽ
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHuaShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ");

	//add npcs into the room

	add_npc("helpnpc012");		//add by qzj 2001-08-13

	add_door("������", "������", "����");
	add_door("��ľ��", "��ľ��", "����");
	add_door("��ɽ��", "��ɽ��", "����");
	add_door("������", "������", "����");

	add_door("��ɽ����", "��ɽ����", "����");



};


ROOM_END;
