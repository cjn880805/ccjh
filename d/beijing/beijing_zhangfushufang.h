//zhangfushufang.h
//Sample for room: �Ÿ��鷿

ROOM_BEGIN(CRBeiJing_zhangfushufang);

virtual void create()			
{
	set_name( "�Ÿ��鷿");

	set("no_fight",1);
	set("no_cast",1);

	add_npc("zaixiang_zhang");//�ž���
	
	add_door("�����Ÿ�����", "�����Ÿ�����", "�����Ÿ��鷿");
};


ROOM_END;
