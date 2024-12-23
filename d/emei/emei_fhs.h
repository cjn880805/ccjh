//fhs.h

//Sample for room:  ���ҷ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_fhs);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҷ�����");

	add_npc("pub_girldizi");

	add_door("��������1", "��������1", "���ҷ�����");
	add_door("��������2", "��������2", "���ҷ�����");

	set("long","����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬�����ľ���죬���ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ�����ÿ����ƶ�Ρ�롣��ɲ���ڸ��ڴ���Ũ��֮�У�������ȴ��һƬ��Ҷ���������Ͻ����±��ǹ����á�");
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
