//shanlu2.h

//Sample for room: ɽ·2
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·2");

	add_npc("pub_playboy");
	add_npc("pub_guniang");   // add by zdn 2001-07-13

	add_door("�����ɽ·4", "�����ɽ·4", "�����ɽ·2");
	add_door("������黨��", "������黨��", "�����ɽ·2");
	add_door("����Ǳ���ѩɽ", "����Ǳ���ѩɽ", "�����ɽ·2");
	add_door("�����ɽ·3", "�����ɽ·3", "�����ɽ·2");

	set("long", "����һ����ͨ��ʽ��̨����¥������³�������ģ�������������¥��ռ�ع��ö࣬Ҳ�ر�ߴ��������㣬�������Ჿ�ļ�����ݡ��˴��²�Ҳ�������󣬴�ɨ�øɸɾ�������������ֱͨ�ϲ㡣" );
	
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
