//duyezuo.h ���ݶ�Һ�ص���

ROOM_BEGIN(CRhangzhou_duyezuo);

virtual void create()		
{
	set_name( "��Һ�ص���");

	add_door("����ص�", "���ݻ���ص�", "���ݶ�Һ�ص���");
	add_door("��Һ�ص��Ұ�", "���ݶ�Һ�ص��Ұ�", "���ݶ�Һ�ص���");

	set("long","��ǰ��һ��������ɵ�ˮ�ӣ���������������Ķ�Һ�����������ǽ������˼�֮�����ľ綾֮���ʬˮ���������м��и���Ʒ֧��һ�£�����������Ṧ���޷��ɹ��ġ�");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	AddMenuItem("��", "$0tiao $1", me);
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "tiao") == 0)
		return do_tiao(me, arg);
	return 0;
}


int do_tiao(CChar *me, char * arg)
{
	if(me->query_temp("wei/renwu8_9"))
	{
		tell_object(me,"\n$HIC��ʹ��ȫ��һ����ƽƽ���ȵ������˶�Һ�ص��Ұ���");
		me->move(load_room("���ݶ�Һ�ص��Ұ�"));
	}
	else if(me->query_temp("wei/renwu8_8"))
	{
		tell_object(me,"\n$HIC�����һ����������������ͷ�ϡ�");
		me->set_temp("wei/renwu8_9",1);//��������ͷ��
	}
	else
	{
		if(random(2))
			tell_object(me,"\n$HIC���׼������ͻȻ�ŵ�һ�������ı������ס�");
		else
			tell_object(me,"\n$HIC�㿴�����صġ���ʬˮ�������в���ֱ���������Ȳ��ɵĶ���������");
	}
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"��Һ�ص��Ұ�"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR������ô������ģ�", me);
			return 0;
		}
		else
		{
			message_vision("$HIR��ǰ��һ��������ɵ�ˮ�ӣ���������������Ķ�Һ�����������ǽ������˼�֮�����ľ綾֮���ʬˮ���������м��и���Ʒ֧��һ�£�������$N���Ṧ���޷��ɹ��ġ�", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
