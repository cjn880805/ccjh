//huacangan.h
//Sample for room:  ���һ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_huacangan);

virtual void create()			//Call it when Room Create
{
	set_name( "���һ�����");
	add_npc("pub_nigu2");            // add by zdn  2001-07-14
	add_door("���ҽ�", "���ҽ�", "���һ�����");
	add_door("���Ҷù�̨", "���Ҷù�̨", "���һ�����");
//	add_door("����������", "����������", "���һ�����");
	add_door("���һ���������", "���һ���������", "���һ�����");

	set("long","�������ǽ𶥵���Ҫ��������ģ�����������������������𡣻����ֺ���Ƕù�̨���Ա��������֡�");

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
