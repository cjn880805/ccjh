//road1.h

//Sample for room: ������ʯ���1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���1");
	
	add_npc("pub_playboy");            // add by zdn 2001-07-14


	add_door("����������", "����������", "������ʯ���1");
	add_door("���ݷ�����", "���ݷ�����", "������ʯ���1");
	add_door("������ʯ���2", "������ʯ���2", "������ʯ���1");
	add_door("Ȫ��ɽ·3", "Ȫ��ɽ·3", "������ʯ���1");

	set("long","����ϼ�������������������Ϸ�������ο͡����߹���СϪ�����������ˡ��ϱ����Ϸ������·��" );

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
