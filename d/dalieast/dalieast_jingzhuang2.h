//jingzhuang2.h

//Sample for room: ����Ǿ���2
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���2");

//	add_door("����Ǿ���1", "����Ǿ���1", "����Ǿ���2");
//	add_door("����Ǿ���3", "����Ǿ���3", "����Ǿ���2");

	set("long", "Ϊ�������񣬸��б��飬����¡�𣬽�ڱ��֣����Ⱪ�𣬼�������С�" );
	
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
