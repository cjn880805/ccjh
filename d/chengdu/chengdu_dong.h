//chengdu_dong.h


RESIDENT_BEGIN(CRchengdu_dong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɶ���");

	set("resident", "�ɶ�");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");


	add_door("�ɶ���", "�ɶ���", "�ɶ���");
	add_door("�ɶ���������", "�ɶ���������", "�ɶ���");

	add_door("�ɶ���ţ���", "�ɶ���ţ���", "�ɶ���");
	add_door("�ɶ�����¥", "�ɶ�����¥", "�ɶ���");
	add_door("�ɶ�������", "�ɶ�������", "�ɶ���");
	add_door("�ɶ��񶼾�¥", "�ɶ��񶼾�¥", "�ɶ���");
};


RESIDENT_END;
