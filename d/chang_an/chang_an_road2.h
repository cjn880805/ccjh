//road2.h

//Sample for room: ������ٵ�2
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ٵ�2");
	
	//add npcs into the room   2001-07-12-zdn add
	add_npc("pub_huanu");
	add_npc("pub_daoke");
	add_npc("pub_lanlinlaoren");

	add_door("�书", "�书", "������ٵ�2");
	add_door("����ɽ��ٵ�", "����ɽ��ٵ�", "������ٵ�2");
	add_door("�������ȹ�", "�������ȹ�", "������ٵ�2");
	add_door("������ٵ�4", "������ٵ�4", "������ٵ�2");
	add_door("��ɽ����ʯ���", "��ɽ����ʯ���", "������ٵ�2");	


};


CHANGAN_END;
