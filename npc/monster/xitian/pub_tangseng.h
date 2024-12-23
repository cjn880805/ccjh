//tangseng.h
//��ɮ������ΣУá��ƺ��뺣�ڡ�������ˡ���������
//Teapot 2001-02-14
//д��VDay...grin

//�޸ģ�����Ϊ������

NPC_BEGIN(CNpub_tangseng);

void create()
{
	set_name("��ɮ", "tang seng");
	set("title", "�����ް����л��");
	set("gender", "����");
	set("age", 27);
	set("per", 30);
	set("max_hp",7200);
	set("eff_hp",7200);
	set("hp",7200);
	set("combat_exp",0l);
//	set("env/wimpy",100);

	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_monk);

	set_inquiry("ӦƸ", "���������˼��������ٿ����´�ᣬȱ�ټ���������Ա������ȥӦƸ������һ·���ա�����Ը���������");
	set_inquiry("����", agree_help);
	set_inquiry("��������", repair_weapon);	
	set("no_huan",1);
};

static char * repair_weapon(CNpc * me, CChar * who)
{
	char msg[80];

	CContainer * weapon = who->PresentName(snprintf(msg, 80, "s_weapon_%s", who->id(1)), IS_ITEM);

	if(! weapon) return "�����˲���ڿ�û�жϵ�����������̸�����أ�";

	if(weapon->querymap("apply"))
		return "�Ǻǣ��㸣�������컯�����ϵ�������û����";

	if(! CMoney::Player_Pay(who, 50000))
		return "��׼��5������̸�ɡ�ƶɮҲ�����ס���";
				
	weapon->set_name( weapon->querystr("staticname"));
	who->add("teapot/cumpower",-2);
	if(who->query("teapot/cumpower")<0)
		who->del("teapot/cumpower");
		
	weapon->set("cumpower", who->query("teapot/cumpower"));
	weapon->create();		//added by lanwood 2001-03-26	���¼�������ǿ��
	weapon->UpdateMe();
	weapon->Save();
	who->Save();	
	return "�����޺��ˣ�������50000�ֹ��ѡ�";
}

static char * agree_help(CNpc * npc , CChar * player)
{
	CContainer * obj;
	CChar * player2;
	char msg[255];

	if(npc->query("teapot/bl") == 31)
	{
		if(EQUALSTR(npc->querystr("keeper1"), player->querystr("id")))
		{

			player->add("combat_exp", npc->query("keeper1_exp"));
		    message_vision(snprintf(msg, 255, "$N�����%d���飡", npc->query("keeper1_exp")), player, npc);

			g_Channel.do_channel(&g_Channel, 0, "sys", 
				snprintf(msg, 255, "%s������ɮ�����죬���%ld���飡", player->name(1), npc->query("keeper1_exp")));

			npc->del("keeper1");
			npc->del("keeper1_exp");
		}

		if(EQUALSTR(npc->querystr("keeper2"), player->querystr("id")))
		{

			player->add("combat_exp", npc->query("keeper2_exp"));
		    message_vision(snprintf(msg, 255, "$N�����%d���飡", npc->query("keeper2_exp")), player, npc);

			g_Channel.do_channel(&g_Channel, 0, "sys", 
				snprintf(msg, 255, "%s������ɮ�����죬���%ld���飡", player->name(1), npc->query("keeper2_exp")));

			npc->del("keeper2");
			npc->del("keeper2_exp");
		}

		if(! npc->querystr("keeper1")[0] && !npc->querystr("keeper2")[0])
			npc->call_out(selfdest, 3);

		return "������";
	}


	if(npc->querystr("keeper2")[0])
		return "��������������ӦƸ������";

	if(npc->querystr("keeper1")[0] && DIFFERSTR(npc->querystr("keeper1"), player->querystr("id")))
	{
		npc->say("��ɮ����ʩ��һ��������ĿɼΡ�", player);
	
		if( (player->query_combat_exp() > 100000 ) || player->query("teapot/xitian") )
		{
			npc->say("ֻ�������������²�����ɡ�", player);
			npc->SendMenu(player);
			return 0;
		}
	
		if(!random(100))
			player->set("teapot/xitian",1);

		npc->set("keeper2", player->querystr("id"));
		int exp = player->query_combat_exp()/100 + 1;
		npc->set("keeper2_exp", exp + random(exp));

//		player->set_temp("no_move",1);


		obj = npc->environment();
		player2=(CChar * ) obj->present(npc->querystr("keeper1"));

		if(npc->querystr("keeper1")[0] && !player2)
		{
			npc->del("keeper1");
			npc->del("keeper1_exp");
			npc->del("keeper2");
			npc->del("keeper2_exp");
//			player->delete_temp("no_move");
			npc->say("��ѽѽ����֪��������λ����ȥ�����������ɣ�", player);
			npc->SendMenu(player);
			return 0;
		}
		
		player2->delete_temp("teapot/xitian");

		message_vision("��ɮ���˿��������������ӷ𣬰����ӷ����Ǵ���㣬׼�������߰ɡ������ˣ����˰���",npc);


		npc->set("chat_chance", 70);
		npc->set_heart_beat(1);

	}
	else
	{
		npc->say("��ɮ����ʩ��һ��������ĿɼΡ�", player);
	
		if( player->query_combat_exp() > 100000 || player->query("teapot/xitian") )
		{
			npc->say("ֻ�������������²�����ɡ�", player);
			npc->SendMenu(player);
			return 0;
		}

		if (player->query_temp("teapot/xitian"))
		{
			npc->say("���ż������ż����ٵȵȰɡ�", player);
			npc->SendMenu(player);
			return 0;
		}
	
		if(!random(100))
			player->set("teapot/xitian", 1);

		npc->set("keeper1", player->querystr("id"));
		int exp = player->query_combat_exp() / 100 + 1;
		npc->set("keeper1_exp", exp + random(exp));
		npc->say("��ɮ����ֻ�����ֻ��һ�ˣ����ǲ����ɡ��������ٵ�һ�ˣ���Σ�", player);

		player->set_temp("teapot/xitian",1);

//		player->set_temp("no_move",1);
		
		npc->say("���ż����ȵȣ��ٵȵȰɡ�", player);
		npc->SendMenu(player);
	}
	
	return 0;
}

void bl_move()
{
	char msg[255];

	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));

	int i;
	i=query("teapot/bl");

	if (i==31)
	{
	    message_vision("��ɮ���˿��������������������Ư�������Ҿ�����ס�������ˡ�����л��λ��",this);
		set("chat_chance",0l);
		return ;	// ����Ŀ�ĵأ�
	}

	if(!player1 || !player2)
	{
	    message_vision("��ɮ���ҿ������������أ��������ˣ������Ĳ��ϣ���ôȥӦƸ��",this);
		remove_call_out(selfdest);
		call_out(selfdest,3);
		return ;
	}

    message_vision("��ɮ���������л�ɽ髣�ɽ髡�",this);
    message_vision("��ɮ���˿���Χ��Ѹ�����������ȥ��",this);
	
	static char bnline[31][20]={"�ƺӰ���7","�ƺӰ���6","�ƺӰ���5","�ƺӰ���4","�ƺӰ���3","�ƺӰ���2","�ƺӰ���1","�ƺ�μ������","�ƺ�1","�ƺӺ���","�ƺӻ�����ԭ","��ľ�����Ŷɿ�","�ƺ�2","�ƺ�3","�ƺ�����","�ƺ�ɳ��·","�ƺӹ���","�ƺӴ��","�ƺ�������","�ƺ�����","�ƺ�������","�ƺ�ʯϿ��","�ƺӱ�����","�ƺ�Ӫ��ˮ","�ƺӹų���","�ƺ�ʯ��","�ƺӺ�ɽϿ","�ƺӾ�Զ","�ƺ�ɳĮ1","�ƺ�ɳĮ2","�ƺ�ʯ��"};
			
	

	

	CRoom * troom;
	troom=load_room(bnline[i]);

	move(troom);
	player1->move(troom);
	player2->move(troom);

	if (random(3000))
	{
	    message_vision("��ɮ��������ӦƸ������������",this);
	}
	else
	{
	    message_vision("��ɮͻȻʫ�˴󷢡�",this);
	    message_vision("��ɮ������������ʯ���Թ۲׺���ˮ���壣�ɽ����š���ľ�������ٲݷ�ï�������ɪ��",this);
	    message_vision("��ɮ�������鲨ӿ������֮�У��������С��Ǻ����ã���������������գ�����ӽ־��",this);
		message_vision("�������������", this);
		player1->set("teapot/canglang",1);
		player2->set("teapot/canglang",1);
	}

	set("teapot/bl",i+1);

	
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "��ɮ����ӦƸ���ߵ�%s�ˡ�", bnline[i]));


	return ;
}


char * chat_msg()
{

	if (!random(2))
	{
		if(!random(2))
			bl_move();
		else
		{
			if(random(2))
			    message_vision("��ɮ����Only you~~~ you~~~ you~~~��",this);
			else
				call_robber();
		}
	}	
	else
	    message_vision("��ɮ���˵Ŀ�����Χ����������ĵ�ͼ���Ĳ�����",this);

	return "";
}

void call_robber()
{
	CChar * robber;
	CContainer * env = environment();

	CChar * player1;
	CChar * player2;
	player1=(CChar * ) env->present(querystr("keeper1"));
	player2=(CChar * ) env->present(querystr("keeper2"));

	
	CFightRoom * obj;

	tell_room(env, "ͻȻ�����˼�����Ӱ��");

	//while( (obj = (CFightRoom *)env->present("fight_room")) )
	//	obj->End_Fight();		

	obj = (CFightRoom *)env->present("fight_room_tangseng");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "��ɮӦƸ��һ��", "fight_room_tangseng");		
		obj->move(env);

		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

		if(player1) 
		{
			player1->move(obj);
			obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
		}

		if(player2) 
		{
			player2->move(obj);
			obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
		}
	}
	

	for(int i=0;i<random(4)+1;i++)
	{
		robber = load_npc("pub_robber");
		robber->move(obj);
		obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);	
	}

	obj->Begin_Fight(0);	
}



void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	if(random(2)==0)
	    message_vision("$n�ʵ���$N��λʩ�����������Ȥ�ɵ���", who, me);
	else
	    message_vision("��ɮ�����Լ�����ӵ���û�����˵����˽ڡ���", me);

	return;
}


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "��ɮ����һ��������ʧ�ˡ�");
	else
		tell_room(me, "��ɮ����һ��������ʧ�ˡ�");

	destruct(ob);
	return;
}


void die()
{
	selfdest(this, 0, 0);
}

int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	LONG value1;

	if(EQUALSTR(who->querystr("family/family_name"), "ؤ��") && who->query("kill/guilt")<250 )
		value1 = ob->query("value") / 2000;
	else 
		value1 = ob->query("value") / 10000;

	if(value1 < 1) return 0;

	int guilt = who->query("kill/guilt");
	
	guilt -= value1;
	if(guilt < 0) guilt = 0;

	int desc = who->query("kill/guilt") - guilt;
	
	tell_object(who, snprintf(msg, 255, "$HIY�����м�����%ld�㡣\n��ɮ�����ʾ��л��", desc));
	who->set("kill/guilt", guilt);	

	destruct(ob);
	return 1;
}

NPC_END;




