//zhulou3.h

//Sample for room: ����¥
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulou3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	add_npc("pub_jisi");                   //add by zdn 2001-07-13

	add_door("�����³����", "�����³����", "����Ǵ���¥");

	set("long", "����һ����ͨ��ʽ��̨����¥������³�������ģ�������������¥��ռ�ع��ö࣬Ҳ�ر�ߴ��������㣬�������Ჿ�ļ�����ݡ��˴��²�Ҳ�������󣬴�ɨ�øɸɾ�������������ֱͨ�ϲ�" );
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
