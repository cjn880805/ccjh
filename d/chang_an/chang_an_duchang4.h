//duchang4.h

//Sample for room: �������귿
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������귿");

	add_npc("pub_shinu1");   //zdn 2001-07-12 add

	add_door("�����ַ���¥����", "�����ַ���¥����", "�������귿");

	set("long", "һ����ɫ���ο�̴�㿿���������������ܷ���һȦ�����ž۾�����Ŀ��ˡ��м���һ��ʯ�����������һ����������̴��̨��һλ�������ݵĹ�ͯ��Χ�Ź�̨ת��תȥ���귿�����ǽ�Ϲ�������(paizi)�� " );
	set("light_up",  1);
	set("no_fight",  1);
	set("no_magic",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
CHANGAN_END;
