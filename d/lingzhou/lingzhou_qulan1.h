//qulan1.h

//Sample for room: ��С��


ROOM_BEGIN(CRLingZhou_qulan1);

virtual void create()		
{
	set_name( "����");

	add_door("���ݻʹ���С��", "���ݻʹ���С��", "���ݻʹ��󹬻���");
	add_door("���ݻʹ�������2", "���ݻʹ�������2", "���ݻʹ�������1");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");
	add_npc("lj_gongnv");

};

ROOM_END;
