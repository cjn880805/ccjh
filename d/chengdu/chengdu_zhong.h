//chengdu_zhong.h


RESIDENT_BEGIN(CRchengdu_zhong);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɶ���");

	set("resident", "�ɶ�");

	//add npcs into the room
	add_npc("pub_tangruei");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("pub_guanbing1");
	add_npc("pub_weiziyi");

	add_door("�ɶ���", "�ɶ���", "�ɶ���");
	add_door("�ɶ���", "�ɶ���", "�ɶ���");
	add_door("�ɶ�������", "�ɶ�������", "�ɶ���");

	add_door("�ɶ��ᶽ��", "�ɶ��ᶽ��", "�ɶ���");

};


RESIDENT_END;



