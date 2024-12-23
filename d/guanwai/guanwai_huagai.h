//huagai.h

//Sample for room: ���Ƿ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_huagai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ƿ�");

	set("monster_chance", 50);
	
	add_npc("pub_youke");    // add by zdn 2001-07-13

	add_door("��������", "��������", "���⻪�Ƿ�");
	add_door("�����ͷɽ���1", "�����ͷɽ���1", "���⻪�Ƿ�");

    set("long","���׶�����߷壬�Թ����������Ƿ���Ƿ�������Ĺʵ��������𴦣�ǡ���ƿ�����һ�㣬������������ˮ���죬һ����������׳���ģ��������Ƿ塣" );

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
