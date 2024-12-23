//gudao.h

//Sample for room: �ŵ�
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_gudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ŵ�");

	add_npc("pub_youke");
	add_npc("pub_playboy");   // add by zdn 2001-07-13

	add_door("���������Ϫ�ذ�", "���������Ϫ�ذ�", "����ǹŵ�");
	add_door("�����ɽ·6", "�����ɽ·6", "����ǹŵ�");
	add_door("��������廪¥", "��������廪¥", "����ǹŵ�");

	set("long", "һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ����������һ���޼ʵ���˫���ɴ�ɭ�֡����������һƬ��ΰ������һ�������ĺ�ǽ������Խ��ǽͷ�ɼ�һ����¥���������Ǵ�����ʤ�廪¥��" );
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
