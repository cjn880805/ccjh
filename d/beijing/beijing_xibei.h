//beijing_xibei.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_xibei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");
	set("capacity", 50);

	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("mingjiao_baiguishou");

	add_door("������Ժ", "������Ժ", "��������");
	add_door("��������", "��������", "��������");
	add_door("�����ĳ�", "�����ĳ�", "��������");
	add_door("������������", "������������", "��������");
	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");


};


RESIDENT_END;