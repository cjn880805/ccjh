//xichansi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xichansi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_guest");
	add_npc("pub_kongchan");
	
	add_door("������", "������", "����������");

    set("long", "������ʼ�����������������¥���Ϊ�����ͣ�����ׯ�ϣ�������𲻾�������������������󣬶�����顣" );
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
