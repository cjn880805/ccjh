//suzhoubei.h

//Sample for room:  ���ݱ�
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhoubei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݱ�");

	set("resident", "����");
	set("capacity", 35);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("������ʯ�ٵ�2", "������ʯ�ٵ�2", "���ݱ�");
	add_door("������", "������", "���ݱ�");

	add_door("���ݿ͵�", "���ݿ͵�", "���ݱ�");
	add_door("�����Ͻ���", "�����Ͻ���", "���ݱ�");
	add_door("����Ϸ԰��", "����Ϸ԰��", "���ݱ�");
	add_door("���ݴ���¥", "���ݴ���¥", "���ݱ�");
};

RESIDENT_END;
