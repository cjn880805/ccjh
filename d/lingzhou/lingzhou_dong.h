//lingzhoucity.h

//Sample for room:  ���ݶ�
//coded by zwb
//data: 2000-11-16

RESIDENT_BEGIN(CRLingZhou_dong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ�");


	set("resident", "����");
	set("capacity", 25);
	
	add_npc("pub_boy");
	add_npc("pub_xiaowei");       //add by zdn 2001-07-14


	add_door("��������", "��������", "���ݶ�");

	add_door("���ݴ󽫾���", "���ݴ󽫾���", "���ݶ�");
	add_door("������", "������", "���ݶ�");

	add_door("����������1", "����������1", "���ݶ�");


};


RESIDENT_END;
