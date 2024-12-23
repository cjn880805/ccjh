//road.h

//Sample for room:  �����̴��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_road);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̴��");

	add_npc("shenlong_zhang");
	add_npc("pub_longyun");

	add_door("�����̿յ�", "�����̿յ�", "�����̴��");
	add_door("�����̴���", "�����̴���", "�����̴��");

	set("long", "����һ�����Ĵ����ȫ����ʯ�ѳ�,��Ȼ�����˲�������.������һƬ������.");
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
//last, register the room into ../server/RoomSetup.cpp
