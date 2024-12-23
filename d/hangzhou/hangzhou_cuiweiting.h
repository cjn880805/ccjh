//cuiweiting.h

//Sample for room: ���ݴ�΢ͤ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_cuiweiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݴ�΢ͤ");
	
	add_npc("pub_youke");         // add by zdn 2001-07-14
	add_npc("pub_shangguannanyan");
	add_door("�������ֶ�", "�������ֶ�", "���ݴ�΢ͤ");

	set("long","��΢ͤ���ڷ�����İ�ɽ�䣬������������Ϊ�������ɶ����ġ������С����곾�������£�����Ѱ���ϴ�΢����ʫ�䣬��ͤ������΢������������ɽ��·��" );

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
