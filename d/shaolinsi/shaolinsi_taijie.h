//taijie.h

//Sample for room: ������̨��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_taijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������̨��");
	
	add_npc("pub_sixinzhe");

	add_door("������ɽ�ŵ�", "������ɽ�ŵ�", "������̨��");
	add_door("������������", "������������", "������̨��");

};

ROOM_END;
