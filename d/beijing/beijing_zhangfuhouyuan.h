//zhangfuhouyuan.h
//Sample for room: �Ÿ���Ժ


ROOM_BEGIN(CRBeiJing_zhangfuhouyuan);

virtual void create()			
{
	set_name( "�Ÿ���Ժ");

	add_npc("pub_binv");//�Ů
	add_npc("pub_binv");
	
	add_door("�����Ÿ�����", "�����Ÿ�����", "�����Ÿ���Ժ");

};


ROOM_END;
