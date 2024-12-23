//bed_room.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_bed_room);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");


	add_door("��ٹ�С��", "��ٹ�С��", "��ٹ�����");

	set("long","�����ӹ��������ң����ڴ������ʹ��ڴ���ľ��֮�ϡ�ǽ�������˸��ֻ������̵Ķ����������и�С�񣬹��Ϸ���һյ���͵ơ�");
	
	set("sleep_room", 1);	//add by lanwood
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
