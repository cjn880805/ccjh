//fuzhou_dong.h

//Sample for room:  ���ݶ�
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRfuzhou_dong);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ�");

	set("resident", "����");
	set("capacity", 15);

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");


	if (random(2)==0)
	{
	add_npc("pub_boy");
	add_npc("pub_playboy");
	}

	add_door("������", "������", "���ݶ�");

	add_door("����ӿȪ��", "����ӿȪ��", "���ݶ�");
	add_door("����������", "����������", "���ݶ�");
	add_door("�����ų���", "�����ų���", "���ݶ�");


};


RESIDENT_END;
