//majiu.h

//Sample for room: ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");


	//add npcs into the room
//	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
//	add_npc("pub_mafu");


	add_door("������Զ", "������Զ", "������Զ���");

    set("long","���ǹ������ǣ�����ຮ֮�أ��ķ����ʲ��ϡ��������󺺹��ܳԿ࣬����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·�����ѩ���µ�ľ���϶���һ����ľ��(paizi)��" );
    set("no_fight", "1");
    set("no_beg", "1");

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
