//chengdu_xi.h


RESIDENT_BEGIN(CRchengdu_xi);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɶ���");

	set("resident", "�ɶ�");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("pub_wuxing");

	add_door("�ɶ���", "�ɶ���", "�ɶ���");
	add_door("�ɶ��Ϻ���", "�ɶ��Ϻ���", "�ɶ���");

	add_door("�ɶ�������", "�ɶ�������", "�ɶ���");
	add_door("�ɶ����������", "�ɶ����������", "�ɶ���");
	add_door("�ɶ�������ҩ��", "�ɶ�������ҩ��", "�ɶ���");

};


RESIDENT_END;



