//zhenshi.h

//Sample for room: ��ʯ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ");
	
	add_npc("pub_jianke");               //add by zdn 2001-07-16


	add_door("�����Խ�ʯ", "�����Խ�ʯ", "������ʯ");

};

ROOM_END;
