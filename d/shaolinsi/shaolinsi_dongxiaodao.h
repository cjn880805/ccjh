//dongxiaodao.h

//Sample for room: �����¶�����С��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dongxiaodao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����¶�����С��");
	
	add_npc("shaolin_sengbing1");       // add by zdn 2001-07-20

	add_door("������������", "������������", "�����¶�����С��");
//	add_door("�����º���Ժһ��", "�����º���Ժһ��", "�����¶�����С��");
	add_door("�����·���¥", "�����·���¥", "�����¶�����С��");

};

ROOM_END;