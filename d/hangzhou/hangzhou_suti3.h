//suti3.h

//Sample for room: �����յ�3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�3");
	
	add_npc("pub_girl1");       //add by zdn 2001-07-14


	add_door("�����յ�2", "�����յ�2", "�����յ�3");
	add_door("�����յ�4", "�����յ�4", "�����յ�3");

	set("long"," ��������ѩ�����У���������̤ѩ�۾����ӵ��ϼ�ĿԶ����ֻ�������������֡������Ƕ����ţ�������ѹ���š�");

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
