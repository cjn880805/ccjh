//yingyue_si.h ����֮��

ITEM_BEGIN(CIyingyue_si);

virtual void create(int nFlag = 0)		
{
	set_name("����֮��","yingyue si");
	set("long","һ�������ε���ʯ��ͨ��ɢ��������ɫ��Ө�⣬��������ֻ���������ˣ���˿��û�ж��ֵĸо���������������ħ���㡣");
	
	set("value", 0l);
	
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_give", 1);
	set("no_get", 1);
		
};

//��������
void init()
{
	CContainer * env = environment();
	
	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		if(env->query("xy/save"))
			env->set_temp("no_fei_1",1);
		return;
	}
}

int query_autoload()
{
	return 1;
}


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("������ս���У��޷�ʹ������֮�ס�");
	
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;
	while(p)
	{
		obj = list->GetNext(p);
		if(userp(obj) )
			obj->move(me->environment());
		else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			obj->move(me->environment());
	}
	
	if(me->querymap("xy") && !me->query("xy/renwu1") && !me->query("xy/renwu2") )
	{
		if(!me->query("xy/save"))
			AddMenuItem("��������", "$0ru $1 1", me);
		else
			AddMenuItem("��ң����", "$0chu $1 0", me);
	}
	SendMenu(me);
	
    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "chu")  && me->query("xy/save") && me->querymap("xy") 
		&& !me->query("xy/renwu1") && !me->query("xy/renwu2")
		&& EQUALSTR(querystr("owner"),me->id(1)))
		return do_chu(me, arg);
	
	if( !strcmp(comm, "ru") && !me->query("xy/save") && me->querymap("xy") 
		&& !me->query("xy/renwu1") && !me->query("xy/renwu2")
		&& EQUALSTR(querystr("owner"),me->id(1)))
		return do_ru(me, arg);
	
	return CItem::handle_action(comm, me, arg);
}

int do_ru(CChar *me, char * arg)
{
	message_vision("\n$HIRֻ��$N�ó�����֮�ף�ĬĬ������һ�����������$N��ʧ�ڿ����С�", me);
	me->move(load_room("��ң��СϪ��"));
	me->set_temp("no_fei_1",1);//�����ڼ䣬��ֹ����
	message_vision("$HIR��â��ɢȥ��$N����Ӱ¶�˳�����\n", me);
	return 1;
}

int do_chu(CChar *me, char * arg)
{
	message_vision("\n$HIRֻ��$N�ó�����֮�ף�ĬĬ������һ�����������$N��ʧ�ڿ����С�", me);
	me->move(load_room("��ɽ������"));
	me->del("xy/save");
	me->set("start_city", START_ROOM);
	me->delete_temp("no_fei_1");
	message_vision("$HIR��â��ɢȥ��$N����Ӱ¶�˳�����\n", me);
	if(me->query("xy/renwu8_1"))
	{
		me->set_temp("xy/renwu8_1",1);//Ϊ����������ۣ�����Ѱҽ
	}
	return 1;
}
ITEM_END;