//fuzhou_nan.h

//Sample for room:  ������
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRfuzhou_nan);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("��������", "��������", "������");
	add_door("���ݶ�", "���ݶ�", "������");
	add_door("������", "������", "������");
	add_door("����У��", "����У��", "������");
	add_door("����������լ", "����������լ", "������");

	add_door("�����ӻ���", "�����ӻ���", "������");
	add_door("����ζ��ζ", "����ζ��ζ", "������");
	add_door("�����ᶽ����", "�����ᶽ����", "������");

};


RESIDENT_END;
