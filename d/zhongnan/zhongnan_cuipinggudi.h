//zhongnan_cuipinggudi.h ����ɽ�����ȵ�
//�ز� 2002��3��14

ROOM_BEGIN(CRZhongNan_cuipinggudi);

virtual void create()			
{
	set_name( "����ɽ�����ȵ�");

	add_npc("gumu_lin");

//	add_door("����ɽ������", "����ɽ������", "����ɽ�����ȵ�");

};


virtual int do_look(CChar * me)
{
	say("��������ɽ�´����ȡ��������ģ�ï��Ũ������͸��֦Ѿ������ķ�϶���䵽���ش�΢��,����ֱ������СϢƬ�̡�" ,me);
	if (me->query_temp("gumu/tan"))
	{
		say("���Ե�ɽ�����ƺ���������ɫ�����٣������������(pa)��ȥ��" ,me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (me->query_temp("gumu/tan") && strcmp(comm, "pa") == 0)
	{
		message_vision("$N���㲢�ã�˳��ɽ���ϳ���������������ȥ������", me);
		me->move(load_room("����ɽ������"));
		return 1;
	}
	return 0;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp




