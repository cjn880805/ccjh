//XiangYang_dongnan.h

RESIDENT_BEGIN(CRXiangYang_dongnan);

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
	add_npc("pub_girl1");	//add by zdn 2001-07-20
	}
	add_door("�������1", "�������1", "��������");
	add_door("�������2", "�������2", "��������");
	add_door("����ľ����", "����ľ����", "��������");
	add_door("����������", "����������", "��������");
	add_door("����ѧ��", "����ѧ��", "��������");
	add_door("����ҩ��", "����ҩ��", "��������");
	add_door("��������¥", "��������¥", "��������");

	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	set("no_cast",  1);
};


RESIDENT_END;
