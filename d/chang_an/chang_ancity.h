//chang_ancity.h

//Sample for room:  ����
//coded by Fisho
//data: 2000-11-3

RESIDENT_BEGIN(CRchang_ancity);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("resident", "����");
	set("capacity", 10);

	add_npc("pub_playboy");
	add_npc("pub_renzhennv");
	add_npc("pub_chezhongnv");
	add_npc("helpnpc014");		//add by qzj 2001-08-13

	add_door("������ٵ�4", "������ٵ�4", "����");
	add_door("���������", "���������", "����");

	add_door("�����ַ�", "�����ַ�", "����");
	add_door("�������Ǯׯ", "�������Ǯׯ", "����");

};


RESIDENT_END;
