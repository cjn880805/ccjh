//zhangfuneitang.h
//Sample for room: �Ÿ�����


ROOM_BEGIN(CRBeiJing_zhangfuneitang);

virtual void create()			
{
	set_name( "�Ÿ�����");

	add_npc("pub_binv");//�Ů
	add_npc("pub_binv");
	
	add_door("�����Ÿ�����", "�����Ÿ�����", "�����Ÿ�����");
	add_door("�����Ÿ��鷿", "�����Ÿ��鷿", "�����Ÿ�����");
	add_door("�����Ÿ���Ժ", "�����Ÿ���Ժ", "�����Ÿ�����");

};


ROOM_END;
