//shulin1.h

//Sample for room: ��Ĺ����1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_shulin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ����1");

	add_npc("pub_playboy");   // add by zdn 2001-07-13

	add_door("��Ĺ�յ�", "��Ĺ�յ�", "��Ĺ����1");
	add_door("��Ĺ����2", "��Ĺ����2", "��Ĺ����1");

	set("long","�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬�������������һȺ���ɫ���۷��������Է�����ȥ��ֻ��һ��ʯ��(shibei)���ڵ��ۨ洦��������һ��յء�����������ï�ܵ����֡�" );

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
