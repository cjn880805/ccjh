//chengducity.h


ROOM_BEGIN(CRchengducity);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɶ�");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("helpnpc011");		//add by qzj 2001-08-13

	add_door("�ɶ��Ϻ���", "�ɶ��Ϻ���", "�ɶ�");
	add_door("�ɶ�������", "�ɶ�������", "�ɶ�");
	add_door("�ɶ���������", "�ɶ���������", "�ɶ�");

	add_door("�ɶ�������ҩ��", "�ɶ�������ҩ��", "�ɶ�");
	add_door("�ɶ����������", "�ɶ����������", "�ɶ�");
	add_door("�ɶ���ţ���", "�ɶ���ţ���", "�ɶ�");
	add_door("�ɶ�����¥", "�ɶ�����¥", "�ɶ�");
	add_door("�ɶ��ᶽ��", "�ɶ��ᶽ��", "�ɶ�");
	add_door("�ɶ�������", "�ɶ�������", "�ɶ�");
	add_door("�ɶ�������", "�ɶ�������", "�ɶ�");
	add_door("�ɶ��񶼾�¥", "�ɶ��񶼾�¥", "�ɶ�");

};


ROOM_END;
