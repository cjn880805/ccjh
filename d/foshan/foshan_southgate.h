//southgate.h

//Sample for room: ��ɽ����
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_southgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");

	set("resident", "��ɽ");

	//add npcs into the room
	add_npc("pub_puren");
	
	add_door("��ɽ", "��ɽ", "��ɽ����");
	add_door("���͵���̲", "���͵���̲", "��ɽ����");


};


RESIDENT_END;
