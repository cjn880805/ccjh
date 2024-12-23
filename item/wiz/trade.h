// �Զ�������
// Lanwood 2001-05-22

ITEM_BEGIN(CItrade);

void create(int nFlag = 0)
{
    set_name("ó������", "trade");
    set_weight(100);
    
	set("long", "���ǹٸ��䷢�Ľ�����ɡ�����ӡ�У���ƽ���ף�ͯ�����ۡ�");        
}

void init()
{
	CContainer * me = environment();

	if(userp(me))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int query_autoload()
{
	CContainer * env = environment();

	if(env && env->query("trade/level"))
		return 1;

	return 0;
}

//���ĳ�����Ƿ���Գ���
int check_validsell(CContainer * obj)
{
	const char * base_name = obj->querystr("base_name");

	if(obj->is_character()) return 0;

	if(EQUALSTR(base_name, "coin")) return 0;
	if(EQUALSTR(base_name, "trade")) return 0;

	CMapping * m = obj->query_entire_dbase();
	if(! m->undefinedp("no_give")) return 0;
	if(! m->undefinedp("no_drop")) return 0;

	//�ж��Ƿ�����
	if( ! m->undefinedp("owner")) return 0;	
	
	return 1;
}

void list_trade(CChar * me)
{
	char msg[80], cmd[40];
	//����
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	int i = 0;
	
	while(p)
	{
		CContainer * obj = list->GetNext(p);
		if(! check_validsell(obj)) continue;
					
		if(DIFFERSTR( obj->querystr_temp("trade/owner"), me->id(1))  )
			obj->delete_temp("trade");					
		
		LONG val = obj->query_temp("trade/value");

		if(val)
			snprintf(msg, 80, "%s ��%ld", obj->name(), val);
		else
			snprintf(msg, 80, "%s ��<����>", obj->name());
		AddMenuItem(msg, snprintf(cmd, 40, "$2value $1 %ld $2", obj->object_id()), me);
		i++;
	}

	 if(! i)
		say("û�п��Խ��׵���Ʒ��", me);	

	 SendMenu(me);
}

int do_use(CChar * me, CContainer * target)
{
	char msg[80], cmd[40];
	CContainer * where;

	if(target == me)
	{		
		say("��Ϊ��Ʒ���ۡ���������ʹ�ñ����ʱ������ʾ�Ѷ��۸����Ʒ�嵥��", me);		
		list_trade(me);		
		return 1;
	}

	//������ʹ�ã���ʾ��֮���ס�
	where = me->environment();
	if(! DIFFERSTR(where->querystr("base_name"), "Ȫ���������ͥ"))
		return notify_fail("����ȫ����Щľͷ�ˣ����ǻ����ط�������ȥ�ɣ�");
	if(! target->is_character())
		return notify_fail("��Ҫ��˭���ף��뿴����㣡");
	if(! living(target))
		return notify_fail("�ȰѶԷ�Ū����˵��");

	CChar * who = (CChar *)target;

	if(who->is_busy() || who->is_fighting())
		return notify_fail("�Է���Ȼû�����㡣");

	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	int i = 0;
	
	me->say(snprintf(msg, 80, "%s����������", me->name()), who);

	while(p)
	{
		CContainer * obj = list->GetNext(p);
		LONG val = obj->query_temp("trade/value");

		if(val <= 0) continue;
		if(DIFFERSTR(obj->querystr_temp("trade/owner"), me->id(1)) ) continue;
				
		me->AddMenuItem(snprintf(msg, 80, "%s ��%ld", obj->name(), val), snprintf(cmd, 40, "$0buy %ld %ld", me->object_id(), obj->object_id()), who);
		i++;
	}

	me->SendMenu(who);

	message_vision("$N������$n������Ʒ��", me, who);
	if(! i)
		message_vision("$n�����˵Ķ�$N˵��������Ҳûʲô�û�����", me, who);

	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "value") == 0)
	{
		char price[40];
		//���۸�
		analyse_string(arg, price, 40);
		
		CContainer * obj = me->Present(atol(arg));
		if(! obj) return notify_fail("��ѡ����Ʒ��");

		LONG val = atol(price);
		if(val <= 0)
		{
			obj->delete_temp("trade");
			tell_object(me, "ȡ�����ۡ�");
			list_trade(me);
			return 1;
		}

		obj->set_temp("trade/owner", me->id(1));
		obj->set_temp("trade/value", val);

		tell_object(me, "��ɶ��ۣ�");

		list_trade(me);
		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




