//shanlu4.h

//Sample for room: ����ɽ·4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·4");
	
	add_npc("pub_flowerg");        //add by zdn 2001-07-14


	add_door("����ɽ·5", "����ɽ·5", "����ɽ·4");
	add_door("���ݷ�ϲ��", "���ݷ�ϲ��", "����ɽ·4");

	set("long","�����������С·�ϣ�������;ɽ����Ӱ��������У���ʯ�߲��������е��ػ��泩�����ϱ㵽�������á����¾͵���������" );

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
