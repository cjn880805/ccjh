//beijing_dongbei.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_dongbei);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");
	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("pub_playboy");


	add_door("����ȫ�۵¾�¥", "����ȫ�۵¾�¥", "��������");
	add_door("������������", "������������", "��������");
	add_door("��������", "��������", "��������");
	add_door("������¥", "������¥", "��������");
	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	add_door("�����Ÿ�", "�����Ÿ�", "��������");


};


RESIDENT_END;