//xixiaodao.h

//Sample for room: ������������С��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_xixiaodao);

virtual void create()			//Call it when Room Create
{
	set_name( "������������С��");
	
	add_npc("shaolin_sengbing1");   //add by zdn 2001-07-20

	add_door("�����²ؾ���һ¥", "�����²ؾ���һ¥", "������������С��");
	//add_door("�����º���Ժ�Ĳ�", "�����º���Ժ�Ĳ�", "������������С��");
	add_door("�����·���¥", "�����·���¥", "������������С��");

};

ROOM_END;