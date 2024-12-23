//shilin1.h

//Sample for room: �����������ʯ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����������ʯ��");

	add_npc("pub_nongfu");
	add_npc("pub_cunfu");   // add by zdn 2001-07-13

	add_door("����ǳ���", "����ǳ���", "�����������ʯ��");

	set("long", "�ഫ������¡��ң��ʯ��������꣬��ʵ�ʺ죬�����գ�����Ѱ֮���������ʳ������䡣���Լһǧ����Ķ��������ʯ�֣�Сʯ�֣�����ʯ�֣���·��ʯ�������֮һ��ǧ��ȼ磬��С�߰�����Ϊ�ӽ���Զ�۵���һƬ���ܴشأ���ȱ�ٱ仯Ծ�������������ͬ��������Ĵ���Ȼ�ľ���ϸ����ʹ����ʯ����׳��׳�ޣ������ˣ�����������Ф�����滹�١�");
	
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
