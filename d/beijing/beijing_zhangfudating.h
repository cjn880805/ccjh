//zhangfudating.h
//Sample for room: �Ÿ�����


ROOM_BEGIN(CRBeiJing_zhangfudating);

virtual void create()			
{
	set_name( "�Ÿ�����");

	add_npc("pub_binv");//�Ů
	add_npc("pub_binv");
	add_npc("bj_zhangfang");//�ʷ�����
		
	add_door("�����Ÿ�", "�����Ÿ�", "�����Ÿ�����");
	add_door("�����Ÿ�����", "�����Ÿ�����", "�����Ÿ�����");

};


ROOM_END;
