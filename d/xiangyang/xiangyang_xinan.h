//XiangYang_xinan.h


RESIDENT_BEGIN(CRXiangYang_xinan);



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

	add_door("����Ǯׯ", "����Ǯׯ", "��������");
	add_door("�����ϱ�Ӫ", "�����ϱ�Ӫ", "��������");
	add_door("�����ĳ�", "�����ĳ�", "��������");


	
	add_door("��������", "��������", "��������");
	add_door("��������", "��������", "��������");
	add_door("�����ݵ�", "�����ݵ�", "��������");
	set("no_cast",  1);
};


RESIDENT_END;
