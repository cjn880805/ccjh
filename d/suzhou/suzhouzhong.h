//suzhouzhong.h

//Sample for room:  ������
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhouzhong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	set("resident", "����");

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	}
	
	add_door("������", "������", "������");
	add_door("���ݱ�", "���ݱ�", "������");
	add_door("���ݶ���", "���ݶ���", "������");

	add_door("���ݺ�ɽ��", "���ݺ�ɽ��", "������");
	add_door("���ݱ��ͼ�", "���ݱ��ͼ�", "������");
	add_door("������̨ǰ�㳡", "������̨ǰ�㳡", "������");
	add_door("���ݸ���", "���ݸ���", "������");
	add_door("�����鳡", "�����鳡", "������");
	add_door("���ݱ�Ӫ", "���ݱ�Ӫ", "������");
	add_door("����������", "����������", "������");
	add_door("���������", "���������", "������");
	add_door("���ݴ�����", "���ݴ�����", "������");
};

RESIDENT_END;
