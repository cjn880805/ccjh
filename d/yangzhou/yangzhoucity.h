//yangzhoucity.h

//Sample for room:  ���ݳ�
//coded by Fisho
//data: 2000-11-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRyangzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݳ�");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");

	add_door("���ݱ���", "���ݱ���", "���ݳ�");
	add_door("���ݶ���", "���ݶ���", "���ݳ�");
	add_door("��������", "��������", "���ݳ�");
	add_door("��������", "��������", "���ݳ�");

	add_door("���ݱ�Ӫ", "���ݱ�Ӫ", "���ݳ�");
	add_door("���ݵ���", "���ݵ���", "���ݳ�");
	add_door("���ݶĳ�", "���ݶĳ�", "���ݳ�");
	add_door("���ݿ͵�", "���ݿ͵�", "���ݳ�");
	add_door("����Ǯׯ", "����Ǯׯ", "���ݳ�");
	add_door("������Ժ", "������Ժ", "���ݳ�");
	add_door("�������", "�������", "���ݳ�");
	add_door("��������", "��������", "���ݳ�");
	add_door("����ҩ��", "����ҩ��", "���ݳ�");
	add_door("�����ӻ���", "�����ӻ���", "���ݳ�");
	add_door("���ݴ�����", "���ݴ�����", "���ݳ�");
	add_door("��������Ժ", "��������Ժ", "���ݳ�");
	add_door("��������¥", "��������¥", "���ݳ�");
	add_door("�������Ŵ���", "�������Ŵ���", "���ݳ�");
	add_door("���ݲ�������", "���ݲ�������", "���ݳ�");
	add_door("���ݴ������", "���ݴ������", "���ݳ�");

};


ROOM_END;
