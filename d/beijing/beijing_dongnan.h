//beijing_dongnan.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_dongnan);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");
	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("pub_playboy");


	add_door("����Ǯׯ", "����Ǯׯ", "��������");
	add_door("��������Ժ", "��������Ժ", "��������");
	add_door("����������", "����������", "��������");
	add_door("��������", "��������", "��������");
				
	add_door("��������", "��������", "��������");
	add_door("�����ʳ�", "�����ʳ�", "��������");
	add_door("���������1", "���������1", "��������");


};


RESIDENT_END;