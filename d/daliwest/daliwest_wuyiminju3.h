//wuyiminju3.h

//Sample for room: �������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_wuyiminju3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");
	
	add_npc("pub_shaonu");    /// add by zdn 2001-07-13

	add_door("���������", "���������", "������������");
	add_door("����Ǽ������", "����Ǽ������", "������������");

	set("long", "����һ��������ķ��ݡ��˼���������������ɽ�ƿ������ſ�������İ����ʯ�󷿣�װ����Ϊ���ף������Ǿ��ĵ��Ƶģ������ա��¡������Ⱦ�����ͼ���������������������ļ�����ݡ�" );
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
