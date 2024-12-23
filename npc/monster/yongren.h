//yongren.h
//�������
//2001-03-15

//�����Զ��ʺá����������ʺõ����
//���������������֡�
//������������

//2001-04-04
//��������������Ʒ�����Ĺ���
//Ϊֽ�˾����ӡ�

char * check_legal_name(const char * name);
int valid_string(const char * msg);

NPC_BEGIN(CNmonster_yongren);

void create()
{
	set_name("����", "man");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 20);
 //   set("attitude", "friendly");
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("infinity", 1);		//������������

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
				obj->move(load_room("��ɽ������"));
				if(is_master(me))
					message_vision(snprintf(msg, 255, "$HIR���ˣ�%s�����ϲ���һ���˽�%s��������ͼ���죬�Ͽ챨��ѽ��\n", me->name(), obj->name()), this);
				else
					message_vision(snprintf(msg, 255, "$HIR���ˣ�������ϲ���һ���˽�%s��������ͼ���죬�Ͽ챨��ѽ��\n", obj->name()), this);
				message_vision(snprintf(msg, 255, "$HIRֻ�����һ����%s����Я����%s��ʧ��һ�������С�\n", me->name(), obj->name()), this);
			}
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				message_vision(snprintf(msg, 255, "$HIR���ˣ�������ѽ��%s�����Ͼ�Ȼ�����������ڴ�ܣ���ϣ��Ӵ��\n������˹Ź֣�����%s����ͼ���죬���ǸϿ������ɨ�س��űȽϰ�ȫ��\n", me->name(),me->name()), this);
				me->move(load_room("̩ɽ��ʶ�"));
			}
		}
		
		if(me->query("tongji")||me->query("kill/����ʱ��"))
		{
			char msg[255];
			tell_object(me,"��ļ��Ѿ�����⣬�����޷����롣");
			tell_room(me->environment(),snprintf(msg,255,"ֻ����ƹ����һ����%s���˴ӷ���һ�����˳������Ǳ���״���ӿ��ˡ�",me->name()),me);
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
		&& !me->query("xkd/����") && me->query("xkd/�ʸ�"))
	{
		//��ʾ�յ����͵�������
		message_vision("\n$HIR���ˣ��ղ������ؼ�ǰ��������������ģ���Źֵ��ˣ�����һ������˵�ý�������\n", this);
		me->del("xkd");
		me->set("xkd/����",1);
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

	//����Ƿ���ʾ����Ҫ�������ˡ�
	LONG pay = env->query("need_pays");
	if(pay && me->query_temp("warning_pays") != pay)
	{
		char msg[255];
		CChar * master = (CChar *)env->Present(param1);
		if(! master) return;

		me->say(snprintf(msg, 255, "%s���ˣ������յ����ݹ����ʵ����ϼ�%ld�����Ŀ��", 
			master->name(), pay), master);

		me->set_temp("warning_pays", pay);
		me->AddMenuItem("���ɷ����ʵ�", "$0paymoney", master);
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
	//ֻ�����Լ��ļ����趨���˵�
	if(is_master(me))
	{
		if(environment()->query("need_pays"))
			AddMenuItem("���ɷ����ʵ�", "$0paymoney", me);
		if(me->query("lj/tielao/count")&&( me->query("lj/renwu8")||me->query("lj/renwu9")))
		{
			CContainer * env = load_room("���ն�����");
			char msg[255];
			if(!env->query(snprintf(msg,255,"%s",me->id(1))))
				AddMenuItem("��������", "$0lj $1", me);
		}
		AddMenuItem("����", "$2name $1 $2", me);
		AddMenuItem("������", "$2desc $1 $2", me);
		AddMenuItem("���û�ӭ���˴�", "$2welcome1 $1 $2", me);
		AddMenuItem("���û�ӭ���˴�", "$2welcome2 $1 $2", me);
		AddMenuItem("������Ʒ", "$0rent $1 2", me);
		AddMenuItem("������Ʒ", "$0rent $1 1", me);
		AddMenuItem("���", "$0redraw $1", me);
		
	}
			

	//�鿴������Ʒ
	AddMenuItem("������Ʒ", "$0getobj $1 2", me);
	AddMenuItem("�����Ʒ", "$0getobj $1 1", me);
	SendMenu(me);
		
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
		|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N������ü.", me, this);
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
				CContainer * env = load_room("���ն�����");
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
		//�ػ�steal��kill��fight��cast��ָ��
		if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
			|| strcmp(comm, "cast") == 0 )			
		{
			message_vision("$N��$n΢΢һЦ�����ҿ��㻹�Ǹ�����ʵ��ɣ���", this, me);
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

	if(! balance) return notify_fail("����û���۳���Ʒ��");
	CMoney::Pay_Player(me, balance);

	say(snprintf(msg, 80, "�������%ld������", balance), me);
	SendMenu(me);

	//����־
	output_error(snprintf(msg, 255, "%s(%s)��%s������ȡ%ld������", me->name(1), me->id(1), name(1), balance));

	return 1;
}

int do_lj(CChar * me)
{
	CContainer * env=environment();
	if(!me->query_temp("lj/tielao"))
	{
		CContainer * env1 = load_room("���ն�����");
		char msg[255];
		env1->add(snprintf(msg,255,"%s",me->id(1)),1);
		CNpc * tielao = load_npc("lj_tielao");
		tielao->set("owner",atoi(me->id(1)));
		tielao->set("home",env->querystr("base_name"));
		tielao->move(env);
		say("ֻ�������������˽�������ϥ������", me);
		SendMenu(me);
		me->set_temp("lj/tielao",1);
	}
	
	return 1;
}
//�鿴������Ʒ
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

//����
int do_giveme(CChar * me, char * arg)
{
	char msg[255];

	CContainer * obj = Present(atol(arg));
	if(!obj) return notify_fail("û��������Ʒ��");

	if(is_master(me))	//���˵ģ�ֱ�ӹ黹��
	{
		if(obj->move(me))
		{
			obj->delete_temp("yongren");
			say(snprintf(msg, 255, "��ı����⣬����%s�ˡ�", obj->name()), me);
			SendMenu(me);
		}
		return 1;
	}

	LONG price = obj->query_temp("yongren/price");
	if(price < 0) return notify_fail("��������������");

	if(! CMoney::Player_Pay(me, price))
		return notify_fail("��û����ô��Ǯ��");

	if(obj->query_temp("yongren/rent") == 1)
		say(snprintf(msg, 255, "��������%s������%ld��", obj->name(), price), me);
	else
	{
		obj->delete_temp("yongren");	//��ģ�ȥ����ǡ�
		say(snprintf(msg, 255, "��������%s, ����%ld��", obj->name(), price), me);
	}

	if(! obj->move(me))
		obj->move(me->environment());

	SendMenu(me);

	CContainer * where = environment();

	if(! where->LockData(1)) return 0;
	where->Load();
	//Ǯ�ۼӵ��������ϡ�
	where->add("yongren/balance", price * 4 / 5);	//��20%��˰
	where->Save();
	where->LockData(0);

	return 1;
}

//���ĳ�����Ƿ���Գ���
int check_validsell(CContainer * obj)
{
	const char * base_name = obj->querystr("base_name");

	if(EQUALSTR(base_name, "coin")) return 0;
	if(EQUALSTR(base_name, "trade")) return 0;
	if(obj->query("index")) return 0;

	CMapping * m = obj->query_entire_dbase();
	if(! m->undefinedp("no_give")) return 0;
	if(! m->undefinedp("no_drop")) return 0;

	//�ж��Ƿ�������
	if( ! m->undefinedp("owner")) return 0;	
	
	return 1;
}

//�������� 1 �� 2��
int do_rent(CChar * me, char * arg)
{
	say("��ѡ��������������Ʒ��", me);

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
		if(! check_validsell(obj)) continue;	//������

		AddMenuItem(obj->name(), snprintf(msg, 80, "$0value $1 %ld",  obj->object_id()), me); 
	}

	SendMenu(me);
	return 1;
}

//�����Ʒ����
int do_value(CChar * me, char * arg)
{
	CContainer * obj = me->Present(atol(arg));	
	char msg[255];

	if(! obj) return notify_fail("������û��������Ʒ��");

	me->set_temp("yongren/obj", atol(arg));

	if(me->query_temp("yongren/rent") == 1)
		say(snprintf(msg, 255, "%s��ֵ%ld���붨���۸�", obj->name(), obj->query("value")), me);
	else
		say(snprintf(msg, 255, "%s��ֵ%ld���붨���ۼ۸�", obj->name(), obj->query("value")), me);

	AddMenuItem("����", "$1price $1 $2", me);
	AddMenuItem("����", "", me);

	SendMenu(me);

	return 1;
}

//��ɣ�
int do_price(CChar * me, char * arg)
{
	LONG price = atol(arg);
	char msg[255];
	
	CContainer * obj = me->Present(me->query_temp("yongren/obj"));
	if(!obj) return notify_fail("��ѡ����Ʒ��");

	obj->move(this);
	obj->set_temp("yongren/rent", me->query_temp("yongren/rent"));	//�Ƿ����
	obj->set_temp("yongren/price", price);

	say(snprintf(msg, 255, "OK���趨��Ʒ�۸�%ld��", price), me);
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
		say("��������������д�ü��Ư���㡣", me);
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
		say("�������˵Ļ�ӭ��д�ü��Ư���㡣", me);
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
		say("�������˵Ļ�ӭ��д�ü��Ư���㡣", me);
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




