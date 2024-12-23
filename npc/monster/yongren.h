//yongren.h
//玩家仆人
//2001-03-15

//可以自动问好。可以设置问好的语句
//可以设置仆人名字。
//可以设置描述

//2001-04-04
//增加售卖主人物品和租借的功能
//为纸人居增加。

char * check_legal_name(const char * name);
int valid_string(const char * msg);

NPC_BEGIN(CNmonster_yongren);

void create()
{
	set_name("仆人", "man");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 20);
 //   set("attitude", "friendly");
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("infinity", 1);		//不受容量限制

	set("is_user", 1);
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
/*
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		me->set_temp("block_msg/all",1);
		if(EQUALSTR((me->query_weapon())->querystr("id"), "tealeaf"))
			me->command(snprintf(msg, 40, "unwield %ld", (me->query_weapon())->object_id()));

		me->delete_temp("apply");
		me->delete_temp("block_msg/all");

		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
*/
	if(! is_fighting() && userp(me))
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
			{
				obj->move(load_room("佛山北帝庙"));
				if(is_master(me))
					message_vision(snprintf(msg, 255, "$HIR主人，%s的身上藏了一个人叫%s，可能意图不轨，赶快报官呀！\n", me->name(), obj->name()), this);
				else
					message_vision(snprintf(msg, 255, "$HIR主人，你的身上藏了一个人叫%s，可能意图不轨，赶快报官呀！\n", obj->name()), this);
				message_vision(snprintf(msg, 255, "$HIR只见金光一闪，%s身上携带的%s消失在一团迷雾中。\n", me->name(), obj->name()), this);
			}
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				message_vision(snprintf(msg, 255, "$HIR主人，快来看呀，%s的身上居然还有两个人在打架，好希奇哟！\n不过如此古怪，可能%s想意图不轨，还是赶快把他们扫地出门比较安全！\n", me->name(),me->name()), this);
				me->move(load_room("泰山玉皇顶"));
			}
		}
		
		if(me->query("tongji")||me->query("kill/红名时间"))
		{
			char msg[255];
			tell_object(me,"你的家已经被查封，现在无法进入。");
			tell_room(me->environment(),snprintf(msg,255,"只听“乒”地一声，%s被人从房里一脚踢了出来，狼狈万状的逃开了。",me->name()),me);
			me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
			me->add("hp",-100);
		}
		else
		{
			if(is_master(me))
			{
				remove_call_out(do_greeting1);
				call_out(do_greeting1, 2, me->object_id());
			}
			else if(querystr("welcome")[0])
			{	
				remove_call_out(do_greeting2);
				call_out(do_greeting2, 2);
			}
		}
	}
/*	if(is_master(me) && me->query("xkd/lingjiu") && me->query("xkd/gumu") &&me->query("xkd/mingjiao") 
		&& !me->query("xkd/请贴") && me->query("xkd/资格"))
	{
		//提示收到侠客岛请贴；
		message_vision("\n$HIR主人，刚才在您回家前，家里来了两个模样古怪的人，留下一封书信说让交给您！\n", this);
		me->del("xkd");
		me->set("xkd/请贴",1);
		CContainer * bot = load_item("xkd_qingtie");
		bot->set("owner",me->id(1));
		bot->move(me);
	}
*/
}

static void do_greeting1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;		
	CContainer * env = me->environment();
	
	if(! env) return;

	//检查是否提示主人要付房费了。
	LONG pay = env->query("need_pays");
	if(pay && me->query_temp("warning_pays") != pay)
	{
		char msg[255];
		CChar * master = (CChar *)env->Present(param1);
		if(! master) return;

		me->say(snprintf(msg, 255, "%s主人，今日收到房屋管理帐单，合计%ld。请过目。", 
			master->name(), pay), master);

		me->set_temp("warning_pays", pay);
		me->AddMenuItem("缴纳房屋帐单", "$0paymoney", master);
		me->SendMenu(master);
	}
	
	if(me->querystr("welcome_master")[0])
		me->say(me->querystr("welcome_master"));		
}

static void do_greeting2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;		
	me->say(me->querystr("welcome"));		
}

int is_master(CChar * me)
{
	CContainer * where = environment();
	if(EQUALSTR(where->querystr("owner"), me->querystr("id"))
		|| EQUALSTR(where->querystr("second_owner"), me->querystr("id")))
		return 1;

	return 0;
}


int do_talk(CChar *me, char * ask)
{
	//只能在自己的家里设定仆人的
	if(is_master(me))
	{
		if(environment()->query("need_pays"))
			AddMenuItem("缴纳房屋帐单", "$0paymoney", me);
		if(me->query("lj/tielao/count")&&( me->query("lj/renwu8")||me->query("lj/renwu9")))
		{
			CContainer * env = load_room("灵鹫独尊厅");
			char msg[255];
			if(!env->query(snprintf(msg,255,"%s",me->id(1))))
				AddMenuItem("保护铁姥", "$0lj $1", me);
		}
		AddMenuItem("改名", "$2name $1 $2", me);
		AddMenuItem("改描述", "$2desc $1 $2", me);
		AddMenuItem("设置欢迎客人词", "$2welcome1 $1 $2", me);
		AddMenuItem("设置欢迎主人词", "$2welcome2 $1 $2", me);
		AddMenuItem("出售物品", "$0rent $1 2", me);
		AddMenuItem("出租物品", "$0rent $1 1", me);
		AddMenuItem("提款", "$0redraw $1", me);
		
	}
			

	//查看出售物品
	AddMenuItem("购买物品", "$0getobj $1 2", me);
	AddMenuItem("租借物品", "$0getobj $1 1", me);
	SendMenu(me);
		
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
		|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N皱了皱眉.", me, this);
		return 1;
	}


	if(is_master(me))
	{
		if(strcmp(comm, "name") == 0)
			return do_name(me, arg);
		else if(strcmp(comm, "desc") == 0)
			return do_desc(me, arg);
		else if(strcmp(comm, "welcome1") == 0)
			return do_welcome1(me, arg);
		else if(strcmp(comm, "welcome2") == 0)
			return do_welcome2(me, arg);
		else if(strcmp(comm, "rent") == 0)
			return do_rent(me, arg);
		else if(strcmp(comm, "value") == 0)
			return do_value(me, arg);
		else if(strcmp(comm, "price") == 0)
			return do_price(me, arg);	
		else if(strcmp(comm, "redraw") == 0)
			return do_withdraw(me);
		else if(strcmp(comm, "lj") == 0 &&!me->query_temp("lj/tielao") )
		{
			if(me->query("lj/tielao/count")&&( me->query("lj/renwu8")||me->query("lj/renwu9")))
			{
				CContainer * env = load_room("灵鹫独尊厅");
				char msg[255];
				if(!env->query(snprintf(msg,255,"%s",me->id(1))))
				{
					me->start_busy(4);
					return do_lj(me);
				}
			}
		}
	}
	else
	{
		//截获steal，kill，fight，cast的指令
		if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
			|| strcmp(comm, "cast") == 0 )			
		{
			message_vision("$N对$n微微一笑：“我看你还是给我老实点吧！”", this, me);
			return 1;
		}
	}

	if(strcmp(comm, "getobj") == 0)
		return do_getobj(me, arg);
	else if(strcmp(comm, "giveme") == 0)
		return do_giveme(me, arg);
	
	return CNpc::handle_action(comm, me, arg);
}

int accept_object(CChar * me, CContainer * obj)
{
	if(obj->query_temp("yongren/rent"))
		return 1;

	return 0;
}

int do_withdraw(CChar * me)
{
	CContainer * where = environment();
	char msg[255];

	if(! where->LockData(1)) return 0;
	where->Load();
	
	LONG balance = where->query("yongren/balance");	
	where->del("yongren/balance");

	where->Save();
	where->LockData(0);

	if(! balance) return notify_fail("您并没有售出物品。");
	CMoney::Pay_Player(me, balance);

	say(snprintf(msg, 80, "您获得了%ld的利润。", balance), me);
	SendMenu(me);

	//记日志
	output_error(snprintf(msg, 255, "%s(%s)从%s身上提取%ld的利润。", me->name(1), me->id(1), name(1), balance));

	return 1;
}

int do_lj(CChar * me)
{
	CContainer * env=environment();
	if(!me->query_temp("lj/tielao"))
	{
		CContainer * env1 = load_room("灵鹫独尊厅");
		char msg[255];
		env1->add(snprintf(msg,255,"%s",me->id(1)),1);
		CNpc * tielao = load_npc("lj_tielao");
		tielao->set("owner",atoi(me->id(1)));
		tielao->set("home",env->querystr("base_name"));
		tielao->move(env);
		say("只见铁姥推门走了进来，盘膝而坐。", me);
		SendMenu(me);
		me->set_temp("lj/tielao",1);
	}
	
	return 1;
}
//查看售卖物品
int do_getobj(CChar * me, char * arg)
{
	int rent = atol(arg);
	char msg[80], tmp[40];

	DTItemList * list = Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;

	while(p)
	{
		obj = list->GetNext(p);
		if(obj->query_temp("yongren/rent") != rent) continue;
		
		AddMenuItem(snprintf(msg, 80, "%s : %ld", obj->name(), obj->query_temp("yongren/price")), 
			snprintf(tmp, 40, "$0giveme $1 %ld", obj->object_id()), me); 
	}
	
	SendMenu(me);
	return 1;
}

//购买
int do_giveme(CChar * me, char * arg)
{
	char msg[255];

	CContainer * obj = Present(atol(arg));
	if(!obj) return notify_fail("没有这样物品。");

	if(is_master(me))	//主人的，直接归还。
	{
		if(obj->move(me))
		{
			obj->delete_temp("yongren");
			say(snprintf(msg, 255, "你改变主意，不卖%s了。", obj->name()), me);
			SendMenu(me);
		}
		return 1;
	}

	LONG price = obj->query_temp("yongren/price");
	if(price < 0) return notify_fail("这样东西不卖！");

	if(! CMoney::Player_Pay(me, price))
		return notify_fail("你没有这么多钱。");

	if(obj->query_temp("yongren/rent") == 1)
		say(snprintf(msg, 255, "你租下了%s，花掉%ld。", obj->name(), price), me);
	else
	{
		obj->delete_temp("yongren");	//买的，去掉标记。
		say(snprintf(msg, 255, "你买下了%s, 花掉%ld。", obj->name(), price), me);
	}

	if(! obj->move(me))
		obj->move(me->environment());

	SendMenu(me);

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();
	//钱累加到主人帐上。
	where->add("yongren/balance", price * 4 / 5);	//扣20%的税
	where->Save();
	where->LockData(0);

	return 1;
}

//检查某货物是否可以出售
int check_validsell(CContainer * obj)
{
	const char * base_name = obj->querystr("base_name");

	if(EQUALSTR(base_name, "coin")) return 0;
	if(EQUALSTR(base_name, "trade")) return 0;
	if(obj->query("index")) return 0;

	CMapping * m = obj->query_entire_dbase();
	if(! m->undefinedp("no_give")) return 0;
	if(! m->undefinedp("no_drop")) return 0;

	//判断是否有主人
	if( ! m->undefinedp("owner")) return 0;	
	
	return 1;
}

//租借或售卖 1 租 2卖
int do_rent(CChar * me, char * arg)
{
	say("请选择租借或售卖的物品。", me);

	DTItemList * list = me->Get_ItemList();
	POSITION p;
	CContainer * obj;
	char msg[80];

	me->set_temp("yongren/rent", atol(arg));
	
	p = list->GetHeadPosition();
	while(p)
	{
		obj = list->GetNext(p);
		if(obj->is_character()) continue;
		if(! check_validsell(obj)) continue;	//不能卖

		AddMenuItem(obj->name(), snprintf(msg, 80, "$0value $1 %ld",  obj->object_id()), me); 
	}

	SendMenu(me);
	return 1;
}

//完成物品定价
int do_value(CChar * me, char * arg)
{
	CContainer * obj = me->Present(atol(arg));	
	char msg[255];

	if(! obj) return notify_fail("你身上没有这样物品！");

	me->set_temp("yongren/obj", atol(arg));

	if(me->query_temp("yongren/rent") == 1)
		say(snprintf(msg, 255, "%s价值%ld，请定租借价格！", obj->name(), obj->query("value")), me);
	else
		say(snprintf(msg, 255, "%s价值%ld，请定出售价格！", obj->name(), obj->query("value")), me);

	AddMenuItem("定价", "$1price $1 $2", me);
	AddMenuItem("放弃", "", me);

	SendMenu(me);

	return 1;
}

//完成！
int do_price(CChar * me, char * arg)
{
	LONG price = atol(arg);
	char msg[255];
	
	CContainer * obj = me->Present(me->query_temp("yongren/obj"));
	if(!obj) return notify_fail("请选定物品！");

	obj->move(this);
	obj->set_temp("yongren/rent", me->query_temp("yongren/rent"));	//是否租借
	obj->set_temp("yongren/price", price);

	say(snprintf(msg, 255, "OK，设定物品价格%ld。", price), me);
	SendMenu(me);

	me->delete_temp("yongren");
	return 1;
}

int do_name(CChar * me, char * arg)
{
	string msg;

	msg = check_legal_name(arg);
	if(msg.length())
	{
		say(msg.c_str(), me);
		SendMenu(me);
		return 1;
	}
	
	set_name( arg);
	UpdateMe();
	
	CContainer * where = environment();
	
	if(! where->LockData(1)) return 0;
	where->Load();

	where->set("yongren/name", arg);
	where->Save();

	where->LockData(0);
	
	tell_object(me, "OK.");
	return 1;
}

int do_desc(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 500)
	{
		say("给您的仆人描述写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}
	
	if(! valid_string(arg) )
		return 0;

	set("long", arg);

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();

	where->set("yongren/long", arg);
	where->Save();

	where->LockData(0);
	
	return 1;
}

int do_welcome1(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 250)
	{
		say("给您仆人的欢迎词写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg))
		return 0;
	
	set("welcome", arg);

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();

	where->set("yongren/welcome", arg);
	where->Save();

	where->LockData(0);

	return 1;
}

int do_welcome2(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 250)
	{
		say("给您仆人的欢迎词写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg))
		return 0;
	
	set("welcome_master", arg);

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();

	where->set("yongren/welcome_master", arg);
	where->Save();

	where->LockData(0);

	return 1;
}

NPC_END;




