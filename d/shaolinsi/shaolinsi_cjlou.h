//cjlou.h

//Sample for room: �ؾ���һ¥
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_cjlou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ؾ���һ¥");

	add_npc("shaolin_dao_yi");
	
	CBox * box = Add_Box();
	box->add_object("fojing11", 1);	
	box->set_name( "����");		

	CBox * box1 = Add_Box();
	box1->add_object("fojing20", 1);	
	box1->set_name( "����");	

	add_door("������������С��", "������������С��", "�����²ؾ���һ¥");
	add_door("�����²ؾ����¥", "�����²ؾ����¥", "�����²ؾ���һ¥");



};


ROOM_END;
