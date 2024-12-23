//huangniling.h

//Sample for room: ���ݻ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huangniling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݻ�����");
	
	add_npc("pub_jianke");
	add_npc("pub_poorman");                   // add by zdn 2001-07-14

	add_door("������ʯ���3", "������ʯ���3", "���ݻ�����");
	add_door("����é�Ҳ�", "����é�Ҳ�", "���ݻ�����");

	set("long","һ������·�������������ܷǳ��İ�����ż���ſ���Щ���˴ҴҶ������ϱ��ֱ�����ɽ��·��" );

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
