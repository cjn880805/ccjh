//ningyuan.h
//Sample for room: ������Զ
//coded by zouwenbin
//data: 2000-11-17


RESIDENT_BEGIN(CRGuanWai_ningyuan);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "������Զ");

	set("capacity", 5);
	set("price", 50);
	set("resident", "������Զ");

	CBox * box = Add_Box();
	box->add_object("blade_book", 2);	
	box->set_name( "����");	

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_yinling");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

//	add_door("������Զ���", "������Զ���", "������Զ");
	add_door("������Զ��Ҥ��", "������Զ��Ҥ��", "������Զ");

	add_door("������Զ�����", "������Զ�����", "������Զ");

	add_door("������ԶС����", "������ԶС����", "������Զ");

	add_door("�����·1", "�����·1", "������Զ");
	add_door("����ѩ��1", "����ѩ��1", "������Զ");

	add_door("����ٵ�", "����ٵ�", "������Զ");


};

RESIDENT_END;
