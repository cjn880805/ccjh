//yangzhou_xinan.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_xinan);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub3_xunbu");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");


	add_door("���ݴ������", "���ݴ������", "��������");
	add_door("���ݶĳ�", "���ݶĳ�", "��������");
	add_door("���ݱ�Ӫ", "���ݱ�Ӫ", "��������");
	add_door("�������", "�������", "��������");

	add_door("���ݶ���", "���ݶ���", "��������");
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	

};


RESIDENT_END;
