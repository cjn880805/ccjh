//shulin2.h

//Sample for room: ��Ĺ����2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_shulin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ����2");

	add_npc("animal_dushe");    // add by zdn 2001-07-13

	add_door("��Ĺ����1", "��Ĺ����1", "��Ĺ����2");
	add_door("��Ĺ�ݵ�", "��Ĺ�ݵ�", "��Ĺ����2");

	set("long","�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬�������������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ��߾���ï�ܵ����֡�" );

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
