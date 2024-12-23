//taiyi.h

//Sample for room: ����ɽ̫�ҳ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_taiyi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ̫�ҳ�");

	//add npcs into the room   2001-07-10 zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");
	add_npc("pub_manxiangke");

	add_door("����ɽɽ��3", "����ɽɽ��3", "����ɽ̫�ҳ�");

	set("long","����ǰ����һ��ɽ������������������̫�ҳ� (chi)����Ϊ���챦��������ɣ����ܸ߷廷�У�����̲�������ɽ��ˮӰ���羰ʮ��������" );

};


virtual int do_look(CChar * me)
{
	say("����ǰ����һ��ɽ������������������̫�ҳ� (chi)����Ϊ���챦��������ɣ����ܸ߷廷�У�����̲�������ɽ��ˮӰ���羰ʮ��������" ,me);
	if (me->query_temp("gumu/tan"))
	{
		say("������ɽˮ֮�䣬һ����ʯ������Ŀ��ͻ���ڳرߣ����߽���ʯ����һ�����������ƴ���¶����ǰ��ɲ�����£�����ȥ(tiao)�ĳ嶯���̽�Ȼ��ֹ��" ,me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (strcmp(comm, "tiao") == 0)
	{
		if(me->query_temp("gumu/tan") )
		{
			message_vision("$N׳��׳�����۾�һ�գ���ס��������һ������", me);
			if(random(2))
			{
				me->set_temp("gumu/ask",1);
				me->delete_temp("gumu/tan");
				me->move(load_room("����ɽ�����ȵ�"));
			}
			else
				me->move(load_room("����ɽС�ӱ�"));		
			me->unconcious();
			return 1;
		}
	}
	return 0;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp




