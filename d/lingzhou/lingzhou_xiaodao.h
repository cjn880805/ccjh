//xiaodao.h

//Sample for room: ��С��


ROOM_BEGIN(CRLingZhou_xiaodao);

virtual void create()		
{
	set_name( "��С��");

	add_door("���ݻʹ���������", "���ݻʹ���������", "���ݻʹ���С��");
	add_door("���ݻʹ�������1", "���ݻʹ�������1", "���ݻʹ���С��");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");
	add_npc("lj_gongnv");

};

ROOM_END;
