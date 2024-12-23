//chashi.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_chashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_susu");             // add by zdn 2001-07-14

	add_door("��������", "��������", "���ݲ���");

	set("long","��������������ҡ����������Ʒ�������ʵ�������" );
	

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
