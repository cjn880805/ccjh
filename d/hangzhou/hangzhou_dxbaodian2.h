//dxbaodian2.h

//Sample for room: ���ݴ��۱���2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dxbaodian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݴ��۱���2");
	
	add_npc("pub_lady3");           // add by zdn 2001-07-14

	add_door("���ݴ��۱���1", "���ݴ��۱���1", "���ݴ��۱���2");

	set("long","��������һ�����������������ж�ʮ������ķ��񣬴���������ʮ���κ����񣬵�������̬����Ĵ�С����һ����ʮ����" );

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
