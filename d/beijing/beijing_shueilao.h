//shueilao.h ˮ��

ROOM_BEGIN(CRBeiJing_shueilao);

virtual void create()
{
	set_name( "ˮ��");
	set("no_fight",1);
	set("no_cast",1);

	set("long", "����һ�������ĵ���ˮ�Ρ�����վ��ˮ������һ������������ʯ�ϡ����ɸߵ��η����ϣ�һ����ڴ�С�ķ���͸��һ��ϸϸ�Ĺ�����" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		double value = 480;		//8����
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set_temp("wei/endtime",t);
		me->call_out(do_jianshi, 480);
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query_temp("wei/renwu2_1"))
	{
		double value = 480;		//8����
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set_temp("wei/endtime",t);
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

static void do_jianshi(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;
	time(&t);
	if(me->query_temp("wei/renwu2_1") && EQUALSTR((me->environment())->querystr("base_name"),"������¥ˮ��" ))
	{
		tell_object(me, "\n$YEL��ˮ�ζ��ķ�������Լ����˵����������");
		if(t>=me->query_temp("wei/endtime"))
		{
			tell_object(me, "$YEL�ζ�������һ�������¿���һ�ۣ�������һ���������ã���ôһ�㶯��Ҳû�У��ǲ������ˣ���");
			tell_object(me, "$YELֻ����ˮ�ζ��Ϻ�¡¡һ�����죬�ƺ���һ���ʯ���ƿ�ȥ��¶����һ�����߼����Ĵ󶴡�");
			tell_object(me, "$YEL�Ӵ󶴴����¼������������������㹴�˳�ȥ��");
			me->delete_temp("wei/endtime");
			me->set_temp("wei/renwu2_2",1);//�ӵ����г���
			me->move(load_room("������¥"));
		}
		else
		{
			tell_object(me, "$YEL�ζ�������һ�������¿���һ�ۣ�˵������û�£��ܲ��ˣ���");
			me->call_out(do_jianshi, 480);
		}
	}
}
ROOM_END;
