//shufang.h

//Sample for room: �鷿
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�鷿");

	add_npc("dali_zhudanchen");	

	add_door("�������������", "�������������", "����������鷿");

	set("long", "���Ǵ�������������鷿����������һ����ľ�����Ϸ��Ų����飬��ǽ�ĵط�����һ����ܣ����������������￴�顣" );

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
