//wuyiminju4.h

//Sample for room: �������4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_wuyiminju4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������4");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("�������Ϫ��", "�������Ϫ��", "������������4");

	set("long", "����һ����ľ����Ƥ��ɵ�������ӡ��˵صĴ�����Ҫ���¸���������ʵ�л����ָ������ò�����Ǩ�㣬������ᶼ�ļ�ª��˵�Ƿ��ᣬ������˵�������񣬲𡢽��������㡣--����ǣ���ȥ�������ɽ�����ڽӽ��������ģ�����·�������൱ƽ��������ɽ����᫣���·�������ѡ�" );
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
