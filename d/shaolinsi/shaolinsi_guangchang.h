//guangchang.h

//Sample for room: �����¹㳡
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_guangchang);

virtual void create()			//Call it when Room Create
{
	set_name( "�����¹㳡");

	add_npc("shaolin_qing_shan");
	add_npc("shaolin_qing_wei");
	add_npc("shaolin_qing_wu");
	add_npc("shaolin_qing_fa");

	add_door("������ǧ���", "������ǧ���", "�����¹㳡");
	add_door("�����µزص�", "�����µزص�", "�����¹㳡");
	add_door("�����·���¥", "�����·���¥", "�����¹㳡");
	add_door("�����°��µ�", "�����°��µ�", "�����¹㳡");

};

ROOM_END;