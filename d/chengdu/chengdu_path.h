//path.h

//Sample for room: Ϫ��С·
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_path);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ϫ��С·");

	add_npc("pub_girl1");    // zdn 2001-07-12 add
	add_npc("pub_boy");

	add_door("�ɶ��Ÿ�����", "�ɶ��Ÿ�����", "�ɶ�Ϫ��С·");
	add_door("�ɶ��Ϻ���", "�ɶ��Ϻ���", "�ɶ�Ϫ��С·");

	set("long",	"ϪԴת��������ˮ���������������ǰ��վ�ڲ����ձ�ǰ������佻�Ϫ���������Ư׹����Ů���佻�ʱ�ڣ�����һ����ζ�����߾��ǡ���������լ���ٻ�̶��ׯ���ĶŸ������ˡ�"	);

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
