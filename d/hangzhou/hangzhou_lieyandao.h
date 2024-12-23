//duyezuo.h ��������ص�

ROOM_BEGIN(CRhangzhou_lieyandao);

virtual void create()		
{
	set_name( "����ص�");

	add_door("��Һ�ص��Ұ�", "���ݶ�Һ�ص��Ұ�", "��������ص�");
	add_door("�����ص�", "���������ص�", "��������ص�");

	set("long","һ�����ȵĿ��������������ǰ������ȼ�յ��һ�");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if (me->query_temp("wei/renwu8_5"))
	{
		AddMenuItem("��", "$0wa $1", me);
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		tell_object(me,"\n$HIRһ�����ȵĿ��������������ǰ������ȼ�յ��һ�");
		me->call_out(do_time, 5);
	}
}

static void do_time(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	if(EQUALSTR(env->querystr("base_name"),"��������ص�"))//������ص���
	{
		tell_object(me, "\n$HIRͻȻһ�����ȵĿ���ӭ���������������������������25���˺���\n");
		me->add("hp",-25);
		if(me->query("hp")<1)
			me->set("hp",1);
		me->UpdateMe();
		me->call_out(do_time, 5);
	}
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
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
				if(me->query_temp("wei/renwu8_7"))
				{
					tell_object(me,"\n$HIW��Һ��ˮ���������˹������𽥰����������ˣ�ֻ����һ����ȼ�յ������");
					me->set_temp("wei/renwu8_10",1);//�������ڳ�С����������
				}
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

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�����ص�"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR������ô������ģ�", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_10") || !me->query_temp("wei/renwu8_7") )
			{
				message_vision("$HIRһ�����ȵĿ��������������ǰ������ȼ�յ��һ�$N���ɵĵ��˼�����", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
