//suti2.h

//Sample for room: �����յ�2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�2");
	
	add_npc("pub_bing");        // add by zdn 2001-07-14


	add_door("�����յ�1", "�����յ�1", "�����յ�2");
	add_door("�����յ�3", "�����յ�3", "�����յ�2");
	add_door("������Ժ���", "������Ժ���", "�����յ�2");

	set("long"," �յ��ϣ��ο����е���������������ʫ����̸���ۣ��е������ʯ����ˮ�������е��������ߣ���������������ǿ���ţ������Ƕ����ţ�������ȥ��԰��ɡ�");

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
