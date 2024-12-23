//rongcheng2.h

//Sample for room: �ų����¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_rongcheng2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ų����¥");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13

	add_door("�����ų���", "�����ų���", "�����ų����¥");

	set("long", "����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������㿴���������Ŵ��ǿյģ���������ŵ����˹�ȥ��" );

	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);
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
