//fzroad.h

//Sample for room: �������д��
//coded by zouwenbin
//data: 2000-11-13

RESIDENT_BEGIN(CRfuzhou_fzroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������д��");

	set("resident", "����");

	add_npc("pub_xiaozei");   // add by zdn 2001-07-13
	add_npc("pub_hongzhoushushen"); 

	add_door("������", "������", "�������д��");
	add_door("��ɽ����·", "��ɽ����·", "�������д��");
 
};


RESIDENT_END;
