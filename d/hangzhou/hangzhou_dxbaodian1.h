//dxbaodian1.h

//Sample for room: ���ݴ��۱���1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dxbaodian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݴ��۱���1");


	add_door("����������", "����������", "���ݴ��۱���1");
	add_door("���ݴ��۱���2", "���ݴ��۱���2", "���ݴ��۱���1");

	set("long","������������һ���ߴ���ʮ���׵Ĵ�����д�š����۱������ǰ�������˽ǾŲ�ʯ���������ֽ��������" );

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
