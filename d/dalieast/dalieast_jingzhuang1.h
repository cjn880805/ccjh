//jingzhuang1.h

//Sample for room: ����Ǿ���1
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���1");


	add_door("����ǽ�֭����", "����ǽ�֭����", "����Ǿ���1");
//	add_door("����Ǿ���2", "����Ǿ���2", "����Ǿ���1");

	set("long", "���Ĵ������񣬸�Լ�ĳߣ����״��У��ֳָ��ᣬ����ׯ�ء�������̤��ū��һ��ū���Ⱪ���������ߣ�����������ū����������ū���͡�һ�����������ˣ��м�һ������˫�ָ�������һ�㡣����֮�������ķ𾭡�" );
	

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
