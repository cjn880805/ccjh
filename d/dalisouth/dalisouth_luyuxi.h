//luyuxi.h

//Sample for room: ����Ϫ�ذ�
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_luyuxi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ϫ�ذ�");

	add_npc("pub_girl1");
	add_npc("pub_playboy");   // add by zdn 2001-07-13

	add_door("����ǹŵ�", "����ǹŵ�", "���������Ϫ�ذ�");
	add_door("�����˫����", "�����˫����", "���������Ϫ�ذ�");

	set("long", "һ���Ŀ�����·��������Ϫ�ϰ���ᶫ����һ������Ϫ���̲���������һ������ɽ�����������де���ľ���������Ŷ�Ϫͨ���������ţ���ȥ��Զ�����廪¥�ˡ�" );
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
