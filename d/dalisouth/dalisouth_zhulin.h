//zhulin.h

//Sample for room: ����С·
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С·");

	add_npc("pub_kanzhuren");   // add by zdn 2001-07-13

	add_door("�����ϲ�ݳ�", "�����ϲ�ݳ�", "���������С·");
	add_door("������䶨��", "������䶨��", "���������С·");

	set("long", "һ��С·�����ֶ��������Ϸ��������һ��Ƭ̨���˾۾ӵĴ��򣬶�����ңң����ϲ�ݳǵĳ�ǽ����·��������ï�ܣ�ʱ��̨������������" );
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
