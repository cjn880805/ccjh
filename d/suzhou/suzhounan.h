//suzhounan.h

//Sample for room:  ������
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhounan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	set("resident", "����");

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("pub_playboy");
	add_npc("pub_playboy");

	add_door("������", "������", "������");
	add_door("��������", "��������", "������");

	add_door("������Ժ", "������Ժ", "������");
	add_door("���ݲ��", "���ݲ��", "������");
	add_door("������԰", "������԰", "������");
	add_door("����������", "����������", "������");
	add_door("����ʨ����", "����ʨ����", "������");
	add_door("���ݾ۱�ի", "���ݾ۱�ի", "������");
};

RESIDENT_END;
