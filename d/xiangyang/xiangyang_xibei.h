//XiangYang_xibei.h


RESIDENT_BEGIN(CRXiangYang_xibei);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

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
	add_door("��������Ӫ", "��������Ӫ", "��������");
	add_door("������ջ", "������ջ", "��������");
	add_door("��������Ӫ", "��������Ӫ", "��������");
	add_door("������������", "������������", "��������");
	add_door("���������", "���������", "��������");
	add_door("�������", "�������", "��������");
//	add_door("������У��", "������У��", "��������");
	add_door("��������", "��������", "��������");
	add_door("�������޷�", "�������޷�", "��������");
	add_door("��������ʹ����", "��������ʹ����", "��������");
	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	add_door("�����ݵ�1", "�����ݵ�1", "��������");
	add_door("�������ȹ�", "�������ȹ�", "��������");
	set("no_cast",  1);
};


RESIDENT_END;
