//yangzhou_xibei.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_xibei);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub_gongsundanang");
	add_npc("btshan_ouyangke");


	add_door("��������", "��������", "��������");
	add_door("����Ǯׯ", "����Ǯׯ", "��������");
	add_door("���ݲ�������", "���ݲ�������", "��������");
	add_door("�������Ŵ���", "�������Ŵ���", "��������");

	add_door("��������", "��������", "��������");
	add_door("���ݶ���", "���ݶ���", "��������");
	add_door("���ݱ���", "���ݱ���", "��������");
	

};


RESIDENT_END;
