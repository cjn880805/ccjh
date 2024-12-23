//ztpo1.h

//Sample for room:  ����������1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_ztpo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������1");

	add_npc("pub_youke");      // add by zdn 2001-07-14
	
	add_door("����������2", "����������2", "����������1");
	add_door("��������ʯ", "��������ʯ", "����������1");

	set("long","����ʯ��ϴ���֮�䣬��·������ʯջ���ݣ�ֱ�����죬ʯ�Ŵ�һǧ���ٶ༶�����ڶ���ɽ���Ͽ���������µ����������ϣ�ǰ������ӣ�һ����졣���·�С������졹����ζ���Ҳ��˶��С������¡������������¶��㵽ϴ��أ����¿ɴ�����ʯ��");

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
