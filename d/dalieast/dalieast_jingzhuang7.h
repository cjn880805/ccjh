//jingzhuang7.h

//Sample for room: ����Ǿ���7
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���7");


//	add_door("����Ǿ���6", "����Ǿ���6", "����Ǿ���7");

	set("long", "�����Ǿ����Ķ�����Բ���ζ���������񷡣�������������𣬷�����ʿ�ȡ�" );
	
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
