ITEM_BEGIN(CIjiashan);

virtual void create(int nFlag = 0)		
{
	set_name( "��ɽ");	
	set("no_get", "��ɽ��Ҳ�ܿ��Ķ���������Ҳ̫�����쿪�˰ɡ�");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("��԰����һͦ���ļ�ɽ��", me);
	if(me->query("lj/jiangli_time"))
	{
		say("������ɽ������˵�ƿ���push����ɽ�Ϳ��Կ����ܵ���", me);
		AddMenuItem("�ƿ���ɽ", "$9push $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "push") == 0)
		return do_push(me, arg);
	return 0;
}

int do_push(CChar *me, char * arg)
{
	if(me->query("lj/jiangli_time"))
	{
		tell_object(me, "\n�㰴����ɽ������˵���ڼ�ɽ�Ķ��Ϸ�������һ�£���ɽ��Ȼ¶��һ����������ڡ�"); 
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj))
				obj->move(load_room("��ɽ������"));
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				me->move(load_room("��ɽ������"));
				me->del("lj/jiangli_time");
				return 1;
			}
		}
		double value = me->query("lj/jiangli_time");		
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set("lj/endtime",t);
		me->del("lj/jiangli_time");
		CContainer * env = load_room("���պ�ɽ�ܵ�1");
		me->move(env);
	}
	return 1;
}

ITEM_END;

