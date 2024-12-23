// 自动售卖机
// Lanwood 2001-05-22

ITEM_BEGIN(CItrade);

void create(int nFlag = 0)
{
    set_name("贸易文书", "trade");
    set_weight(100);
    
	set("long", "这是官府颁发的交易许可。上面印有：公平交易，童叟无欺。");        
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

//检查某货物是否可以出售
int check_validsell(CContainer * obj)
{
	const char * base_name = obj->querystr("base_name");

	if(obj->is_character()) return 0;

	if(EQUALSTR(base_name, "coin")) return 0;
	if(EQUALSTR(base_name, "trade")) return 0;

	CMapping * m = obj->query_entire_dbase();
	if(! m->undefinedp("no_give")) return 0;
	if(! m->undefinedp("no_drop")) return 0;

	//判断是否主人
	if( ! m->undefinedp("owner")) return 0;	
	
	return 1;
}

void list_trade(CChar * me)
{
	char msg[80], cmd[40];
	//定价
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
			snprintf(msg, 80, "%s ：%ld", obj->name(), val);
		else
			snprintf(msg, 80, "%s ：<自用>", obj->name());
		AddMenuItem(msg, snprintf(cmd, 40, "$2value $1 %ld $2", obj->object_id()), me);
		i++;
	}

	 if(! i)
		say("没有可以交易的物品。", me);	

	 SendMenu(me);
}

int do_use(CChar * me, CContainer * target)
{
	char msg[80], cmd[40];
	CContainer * where;

	if(target == me)
	{		
		say("请为商品定价。当对他人使用本物件时，可显示已定价格的商品清单。", me);		
		list_trade(me);		
		return 1;
	}

	//对他人使用，表示与之交易。
	where = me->environment();
	if(! DIFFERSTR(where->querystr("base_name"), "泉州青龙会大庭"))
		return notify_fail("这里全都是些木头人，还是换个地方做生意去吧！");
	if(! target->is_character())
		return notify_fail("你要与谁交易，请看清楚点！");
	if(! living(target))
		return notify_fail("先把对方弄醒再说。");

	CChar * who = (CChar *)target;

	if(who->is_busy() || who->is_fighting())
		return notify_fail("对方显然没空理你。");

	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	int i = 0;
	
	me->say(snprintf(msg, 80, "%s想卖给你货物。", me->name()), who);

	while(p)
	{
		CContainer * obj = list->GetNext(p);
		LONG val = obj->query_temp("trade/value");

		if(val <= 0) continue;
		if(DIFFERSTR(obj->querystr_temp("trade/owner"), me->id(1)) ) continue;
				
		me->AddMenuItem(snprintf(msg, 80, "%s ：%ld", obj->name(), val), snprintf(cmd, 40, "$0buy %ld %ld", me->object_id(), obj->object_id()), who);
		i++;
	}

	me->SendMenu(who);

	message_vision("$N正在向$n推销货品。", me, who);
	if(! i)
		message_vision("$n不高兴的对$N说：可你这也没什么好货啊。", me, who);

	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "value") == 0)
	{
		char price[40];
		//定价格
		analyse_string(arg, price, 40);
		
		CContainer * obj = me->Present(atol(arg));
		if(! obj) return notify_fail("请选定商品。");

		LONG val = atol(price);
		if(val <= 0)
		{
			obj->delete_temp("trade");
			tell_object(me, "取消出售。");
			list_trade(me);
			return 1;
		}

		obj->set_temp("trade/owner", me->id(1));
		obj->set_temp("trade/value", val);

		tell_object(me, "完成定价！");

		list_trade(me);
		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




