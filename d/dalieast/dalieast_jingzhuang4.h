//jingzhuang4.h

//Sample for room: ����Ǿ���4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���4");


//	add_door("����Ǿ���3", "����Ǿ���3", "����Ǿ���4");
//	add_door("����Ǿ���5", "����Ǿ���5", "����Ǿ���4");

	set("long", "���а����������Դ����ж�����������Ŀ���䣬�ݲ��ɱ档�����������������ķ𾭡�����β�����С��ȼú���--�����ˡ�������" );
	
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
