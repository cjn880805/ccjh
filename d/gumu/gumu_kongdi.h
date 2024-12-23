//kongdi.h

//Sample for room: ��Ĺ�յ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ�յ�");

	add_npc("animal_snake");    //add by zdn 2001-07-13

	add_door("��Ĺɽ·", "��Ĺɽ·", "��Ĺ�յ�");
	add_door("��Ĺ����1", "��Ĺ����1", "��Ĺ�յ�");

	set("long","��������ɽɽ������һ��յأ�����ƽ̹������һ��С·ֱ��ɽ赶��ϣ�ͨ��������ɽ���塣�ϱߺ�����һ��Ƭ���֣�ֻ���������������д�����������һ��ɽ·�����Ϻ�������һ��С����");
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
