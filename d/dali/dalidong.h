//dalidong.h

//Sample for room:  ����Ƕ�
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLidong);

virtual void create()			
{
	set_name( "����Ƕ�");

	set("resident", "����");

	add_npc("pub_girl1");
	add_npc("pub_playboy");
	add_npc("pub_playboy");        //zdn 2001-07-12 add
	add_npc("helpnpc_jhlz");

	add_door("�������", "�������", "����Ƕ�");

	add_door("�����ʯ��", "�����ʯ��", "����Ƕ�");
	add_door("�����ҩ��", "�����ҩ��", "����Ƕ�");
	add_door("�����̫�;�", "�����̫�;�", "����Ƕ�");
	add_door("�������������", "�������������", "����Ƕ�");
	add_door("�����Ѧ�ǳ�����", "�����Ѧ�ǳ�����", "����Ƕ�");
};


RESIDENT_END;
