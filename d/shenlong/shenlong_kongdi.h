//kongdi.h

//Sample for room:  �����̿յ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̿յ�");

	add_npc("pub_shennongdizi");
	add_npc("shenlong_su");
	
	add_door("�����̹�ľ��", "�����̹�ľ��", "�����̿յ�");
	add_door("������С��", "������С��", "�����̿յ�");
	add_door("�����̴��", "�����̴��", "�����̿յ�");
	add_door("�����̲�ƺ", "�����̲�ƺ", "�����̿յ�");

	set("long", "����һƬ�յ�,���ܶ�����ʯ,�Ӳݴ�����������һ��С��.����������Ĺ�ľ��.������һ�������Ĵ��,������һƬ��ƺ.");
    
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