//road15.h

//Sample for room: ������ʯ���15
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���15");
	
	
	add_npc("pub_playboy");         // add by zdn 2001-07-14


	add_door("�������ɽ��", "�������ɽ��", "������ʯ���15");
	add_door("������ʯ���16", "������ʯ���16", "������ʯ���15");
	add_door("������ʯ���14", "������ʯ���14", "������ʯ���15");

	set("long"," ��������ˣ����У���˽Σ�����������ϲ��������������������������߸���һ����������ϱ��������ɽ��ɽ·��    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");
    

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
