//sheshenya.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sheshenya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱������");


	add_door("�䵱���ҷ�", "�䵱���ҷ�", "�䵱������");
//	add_door("������ʯ��", "������ʯ��", "�䵱������");

    

/*****************************************************
      set("exits",([  
          "east"     : __DIR__"nanyanfeng",
      ]));
*****************************************************/
};

virtual int do_look(CChar * me)
{
	if(! me->query_temp("mask/������")) return CRoom::do_look(me);

	//ֻ�д�������ȷ�Ĵ𰸲��ܷ�������
	say("����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С�ģ�һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ����", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "jump") == 0)
	{
		message_vision("$N��ס��������һ������", me);

		if(random(3) == 0)
			me->move(load_room("������ʯ��"));
		else
			me->move(load_room("��ң��С��1"));		

		me->unconcious();
		return 1;
	}
	return 0;
}

ROOM_END;
