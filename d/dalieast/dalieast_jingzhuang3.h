//jingzhuang3.h

//Sample for room: ����Ǿ���3
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���3");


//	add_door("����Ǿ���2", "����Ǿ���2", "����Ǿ���3");
//	add_door("����Ǿ���4", "����Ǿ���4", "����Ǿ���3");

	set("long", "��������������������֮������������һ�顣ʶ��ν�����۹���������Ϊ�ز��������������Ŀ�Ͱ�����̾�ϸ������������" );
	
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
