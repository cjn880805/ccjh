//jieyindian.h

//Sample for room:  ���ҽ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jieyindian);

virtual void create()			//Call it when Room Create
{
	set_name( "���ҽ�����");

	add_npc("emei_hui");
	add_npc("emei_wenyin");

	add_door("���Ұ�ʮ����3", "���Ұ�ʮ����3", "���ҽ�����");
	add_door("����������", "����������", "���ҽ�����");

	set("long","�������ұ߱��£��ǽ���졣������һ���ʯ����״���ӣ���������ʯ����������һʯ������ʮ���ɣ��С�����ʯ�����ɴ��������ʼ��������֣����¾�����ʮ���̡���ϴ��ء�");

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
