//jingzhuang6.h

//Sample for room: ����Ǿ���6
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǿ���6");


//	add_door("����Ǿ���5", "����Ǿ���5", "����Ǿ���6");
//	add_door("����Ǿ���7", "����Ǿ���7", "����Ǿ���6");

	set("long", "���������������е��з��񸡵�����������������ܣ���η�����������죬����Э���������Ⱦ����������ɣ��������������������������ǵ���ʯ����������Ʒ���������ļҽ��� �����������˼�ƷҲ ��" );
	
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
