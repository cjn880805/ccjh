//shangu.h

//Sample for room: ��ľ��ɽ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shangu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ɽ��");

	add_npc("pub_ruhua");
	add_door("��ľ���ּ�С��", "��ľ���ּ�С��", "��ľ��ɽ��");
	add_door("��ľ��ʯ��1", "��ľ��ʯ��1", "��ľ��ɽ��");
	add_door("��ľ��������", "��ľ��������", "��ľ��ɽ��");

};


ROOM_END;
