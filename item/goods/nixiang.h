ITEM_BEGIN(CInixiang);

virtual void create(int nFlag = 0)		
{
	set_name( "���µ�����");	
	set("no_get", "�ƺ��������С��һ�㣡");
	set_weight(1);

	call_out(do_die, 1200);
};

virtual int do_look(CChar * me)
{
	say("������ȥ����������۴��綷���������࣬������������ģ����", me);
	if(me->query_temp("wei/renwu8_5"))
	{
		AddMenuItem("������","$9tuei $1",me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(EQUALSTR(environment()->querystr("base_name"),"���ݶ�Һ�ص���" ))
	{
		if(me->query_temp("wei/renwu8_6"))
		{
			if(!strcmp(comm, "tuei"))
			{
				if(me->query("mp_factor")<50)
					tell_object(me,"��ʹ�����̵�����ʹ��������������Ȼ��˿�������ƺ��������С��һ�㣡");
				else
				{
					tell_object(me,"��î�����������һ�����ߡ���˫���������������ϡ�");
					tell_object(me,"�������һ����ǰ��ȥ����������ˮ�����롣��Һֱû�����񾱲���ֻ¶��һ������ͷ�ڶ�Һ֮�ϡ�");
					tell_object(me,"��Ц��Ц�����ú��á�");
					me->set_temp("wei/renwu8_8",1);//�ƶ�������붾Һ�ص�ˮ��
					destruct(this);
				}
				return 1;
			}
		}
	}
	else if(me->query_temp("wei/renwu8_5"))
	{
		if(!strcmp(comm, "tuei"))
		{
			if(me->query("mp_factor")<50)
				say("��ʹ�����̵�����ʹ��������������Ȼ��˿�������ƺ��������С��һ�㣡", me);
			else
			{
				say("�������������񻺻���ǰ��ȥ��", me);
				me->set_temp("wei/renwu8_6",1);//�ƶ�������붾Һ�ص���
				me->move(load_room("���ݶ�Һ�ص���"));
				move(load_room("���ݶ�Һ�ص���"));
			}
			SendMenu(me);
			return 1;
		}
	}
	return CItem::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}
ITEM_END;

