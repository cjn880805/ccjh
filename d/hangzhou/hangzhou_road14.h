//road14.h

//Sample for room: ������ʯ���14
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���14");
	
	add_npc("pub_playboy");      // add by zdn 2001-07-14


	add_door("�����岨��", "�����岨��", "������ʯ���14");
	add_door("���ݺ�������", "���ݺ�������", "������ʯ���14");
	add_door("������ʯ���13", "������ʯ���13", "������ʯ���14");
	add_door("������ʯ���15", "������ʯ���15", "������ʯ���14");

	set("long"," �غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ���־���������һ��԰�����˽���������ʮ�����֡���������ҽ�����࿪��ҩ�̡�    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
