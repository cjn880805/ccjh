//wudang.h

//Sample for room  �䵱
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRWuDangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱");

	add_npc("helpnpc020");		//add by qzj 2001-08-13

	add_door("������", "������", "����");
	add_door("��ɽ", "��ɽ", "����");

    add_door("���", "�䵱���", "����");
    add_door("��԰", "�䵱��԰", "����");
    add_door("���湬", "�䵱���湬", "����");
    add_door("С�Ե�", "�䵱С�Ե�", "����");
    add_door("�����", "�䵱�����", "����");
    add_door("���ҹ�", "�䵱���ҹ�", "����");
    add_door("�����", "�䵱�����", "����");



};


ROOM_END;
