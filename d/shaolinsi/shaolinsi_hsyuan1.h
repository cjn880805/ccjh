//hsyuan1.h

//Sample for room: ����Ժһ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժһ��");

	add_npc("shaolin_hui_he");

	add_door("�����·���¥", "�����·���¥", "�����º���Ժһ��");
	add_door("�����º���Ժ����", "�����º���Ժ����", "�����º���Ժһ��");

};


ROOM_END;
