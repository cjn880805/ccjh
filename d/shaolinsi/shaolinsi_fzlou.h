//fzlou.h

//Sample for room: ����¥
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fzlou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	add_npc("shaolin_dao_pin");

	add_door("�����°����þŲ�", "�����°����þŲ�", "�����·���¥");
	add_door("�������޺��þŲ�", "�������޺��þŲ�", "�����·���¥");

	add_door("�����²���", "�����²���", "�����·���¥");
	add_door("�����º���Ժһ��", "�����º���Ժһ��", "�����·���¥");
	add_door("�����º���Ժ�Ĳ�", "�����º���Ժ�Ĳ�", "�����·���¥");
	
	add_door("������������С��", "������������С��", "�����·���¥");
	add_door("�����¶�����С��", "�����¶�����С��", "�����·���¥");
	add_door("���������䳡", "���������䳡", "�����·���¥");
	add_door("�����¹㳡", "�����¹㳡", "�����·���¥");
	add_door("�����´�ĦԺ", "�����´�ĦԺ", "�����·���¥");

};


ROOM_END;