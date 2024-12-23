//duyeyou.h ���ݶ�Һ�ص��Ұ�

ROOM_BEGIN(CRhangzhou_duyeyou);

virtual void create()		
{
	set_name( "��Һ�ص��Ұ�");

	add_door("��Һ�ص���", "���ݶ�Һ�ص���", "���ݶ�Һ�ص��Ұ�");
	add_door("����ص�", "��������ص�", "���ݶ�Һ�ص��Ұ�");

	set("long","��ǰ��һ��������ɵ�ˮ�ӣ���������������Ķ�Һ�����������ǽ������˼�֮�����ľ綾֮���ʬˮ���������м��и���Ʒ֧��һ�£�����������Ṧ���޷��ɹ��ġ�");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	AddMenuItem("��", "$0tiao $1", me);
	if (me->query_temp("wei/renwu8_5"))
	{
		AddMenuItem("��", "$0wa $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "tiao") == 0)
		return do_tiao(me, arg);
	if(strcmp(comm, "wa") == 0)
		return do_wa(me, arg);
	return 0;
}

int do_wa(CChar *me, char * arg)
{
	CContainer * weapon;
	CContainer * env=me->environment();
	weapon = me->query_weapon();
	char msg[255];
	if (! weapon)
	{
		tell_object(me,"\n$HIR���޴������Ӻ�˵��");
	}
	else
	{
		if(weapon->querystr("owner")[0])
		{
			tell_object(me,snprintf(msg, 255,"\n$HIR����ԥ�Ŀ������е�%s���᲻������ȥ�ھ�",weapon->name(1)));
		}
		else
		{
			if(EQUALSTR(weapon->querystr("base_name"),"tieqiao"))
			{
				tell_object(me,"\n$HIR���������ڵ�������һ��ˮ����");
				tell_object(me,"$HIR��Һ��ˮ���������˹�����");
				tell_object(me,"$HIR���ꡱ��һ�����죬�����Ѿ��������ˡ�\n");
				weapon->move(env);
				destruct(weapon);
				me->set_temp("wei/renwu8_7",1);//�������ڳ�С��
			}
			else
			{
				tell_object(me,snprintf(msg, 255,"\n$HIR��γ�%s������ϴ��˼��£������ž����һ���۶��ˡ�",weapon->name(1)));
				weapon->move(env);
				weapon->set_name(snprintf(msg, 255, "�ϵ���%s", weapon->name(1)));
				weapon->set("value", 0l);
				weapon->del("apply");
			}
		}
	}
	return 1;
}

int do_tiao(CChar *me, char * arg)
{
	if(me->query_temp("wei/renwu8_9"))
	{
		tell_object(me,"\n$HIC��ʹ��ȫ��һ����ƽƽ���ȵ������˶�Һ�ص��󰶡�");
		me->move(load_room("���ݶ�Һ�ص���"));
		me->delete_temp("wei/renwu8_9");
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
	if(EQUALSTR(dir,"���ݶ�Һ�ص���"))
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
