//houdian.h

//Sample for room: ���
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_houdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	add_npc("shaolin_hui_ru");
	add_npc("pub_chenmin");

	add_door("���������޳�", "���������޳�", "�����º��");

	add_door("�����°�����һ��", "�����°�����һ��", "�����º��");
	add_door("�������޺���һ��", "�������޺���һ��", "�����º��");
	add_door("���������䳡", "���������䳡", "�����º��");

	set("valid_startroom",1);
	set("resource/water",1);

};


ROOM_END;
