//beijingcity.h

//Sample for room:  �����ʳ�
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRbeijingcity);


virtual void create()			
{
	set_name( "�����ʳ�");

	add_npc("pub_kunlunnu");
	add_npc("pub_boy");
	add_npc("pub_xiaoguizi");
	add_npc("pub_shamurai");
	add_npc("pub_hai");
	add_npc("helpnpc008");

	add_door("��������", "��������", "�����ʳ�");
	add_door("��������", "��������", "�����ʳ�");
	add_door("���������5", "���������5", "�����ʳ�");
	
	add_door("��������", "��������", "�����ʳ�");
	add_door("�����͵�1", "�����͵�1", "�����ʳ�");
	add_door("�������׳�", "�������׳�", "�����ʳ�");
	add_door("�����������", "�����������", "�����ʳ�");

};


ROOM_END;
