//XiangYang_dongbei.h


RESIDENT_BEGIN(CRXiangYang_dongbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");
	set("capacity", 30);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("helpnpc_jhlz");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("���������ھ�", "���������ھ�", "��������");
	add_door("��������Ӫ", "��������Ӫ", "��������");
	add_door("�������", "�������", "��������");
	add_door("��������������", "��������������", "��������");
	add_door("����������", "����������", "��������");
	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	set("no_cast",  1);
};


RESIDENT_END;
