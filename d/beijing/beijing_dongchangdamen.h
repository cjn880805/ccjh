//dongchangdamen.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_dongchangdamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("pub_bing");
	
	add_door("��������", "��������", "������������");

	set("long", "������Ƕ������ţ����Կ������������̫�ࡣ�����Ʒ��Ĺٱ����ڲ�������ʱ�ش����ź���������㲻�������Ļ�����û��ǸϿ��뿪��" );

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
