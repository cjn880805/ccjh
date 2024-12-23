//jingzhuang6.h
//Sample for room: ����Ǿ���6

ROOM_BEGIN(CRXiaoYao_jingzhuang6);

virtual void create()
{
	set_name( "����Ǿ���6");
	set("no_autosave",1);

	add_door("����Ǿ���5", "��ң�ȴ���Ǿ���5", "��ң�ȴ���Ǿ���6");
	add_door("����Ǿ���7", "��ң�ȴ���Ǿ���7", "��ң�ȴ���Ǿ���6");

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

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"����Ǿ���7"))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu8"))
		{
			me->add_temp("xy/renwu7_2",1);//�չ��ҵ���������������ߴο���
			if(me->query_temp("xy/renwu7_2")>7 )
				return CRoom::valid_leave(me, dir);
		}
		me->move(load_room("��ң�ȴ���Ǿ���1"));
		return notify_fail("�������ǰ��·������ʶ���·��ֻص�����ڡ�");;
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
