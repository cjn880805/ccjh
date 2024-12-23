//suti5.h

//Sample for room: �����յ�5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�5");
	
	add_npc("pub_xiaozei");        //add by zdn 2001-07-14 


	add_door("�����յ�4", "�����յ�4", "�����յ�5");
	add_door("�����յ�6", "�����յ�6", "�����յ�5");

	set("long"," ÿ��ʢ�ģ��ο͵��˷׷�Ѱ��СϢ�������������£�������ġ���������ɽ�ţ����������š�");

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
