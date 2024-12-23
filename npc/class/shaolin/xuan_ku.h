//xuan_ku.h
//Lanwood 2000-01-09

char shaolin_xuan_ku_names[9][20] = {
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",
};

NPC_BEGIN(CNshaolin_xuan_ku);

virtual void create()
{
	set_name("�����ʦ", "xuanku dashi");
	set("long",	"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ������������ƣ��ֱ۴������¶���ƺ��þ���˪��");
	
	set("foolid",105);	set("title", "�����޺�������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set_weight(5000000);

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 3500);
	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);
	set("combat_exp", 800000);
	set("score", 1000000);

// before the modification, all the skills are 120
	set_skill("force", 120);
	set_skill("hunyuan_yiqi", 120);
	set_skill("dodge", 180);
	set_skill("shaolin_shenfa", 180);
	set_skill("parry", 120);
	set_skill("cuff", 185);
	set_skill("staff", 120);
	set_skill("blade", 120);
	set_skill("sword", 120);
	set_skill("luohan_quan", 180);
	set_skill("weituo_gun", 120);
	set_skill("xiuluo_dao", 120);
	set_skill("fumo_jian", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "luohan_quan");
	map_skill("cuff", "luohan_quan");
	map_skill("staff", "weituo_gun");
	map_skill("blade", "xiuluo_dao");
	map_skill("sword", "fumo_jian");

	prepare_skill("cuff", "luohan_quan");

	create_family("������", 36, "����");

	set_inquiry("ʮ���޺���", ask_me);
	set("chat_chance_combat", 45);

	carry_object("jiedao")->wield();
	carry_object("jiasha")->wear();
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("force roar", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

static char * ask_me(CNpc * me, CChar * fighter)
{
	if( fighter->mini_skill() < 80) 
		return "�㹦�������������ʸ��޺�����";
	
	if( fighter->query("luohan_winner") )
		return 	"����Ȼ�����޺����󣬿ɲ�Ҫ�����Ŀ������Ц��";

	if ( EQUALSTR(fighter->querystr("family/family_name"), "������")
		&& fighter->query("family/generation") != me->query("family/generation") + 2)
			return "�㱲�ݲ��ϣ������ʸ��޺�����";

    if ( fighter->query("guilty") > 0 )
		return "���۷����䣬�������������׼���㴳�޺�����";

	if ( me->querystr("assigned_fighter")[0] )
		return "������������ս�޺��������һ��ʱ�������ɡ�";

	fighter->set_temp("xuanku_asked", 1);
	me->say("�ðɣ������ټ��޺��ó������ڶ����䳡���ϣ����Ժ����������䳡�ϵ��㡣");
	me->set("assigned_fighter", fighter->querystr("id")); 		
	
	if( !fighter->query_temp("xuannan_asked") )
		me->say("������ȥ��֪���������Ѵ�ʦ�����������м����������޺��������䳡���ϡ�");

    message_vision("�����ʦ�����뿪��", fighter);

	me->move(load_room("room_void"));
	me->call_out(do_jihe, 5, fighter->object_id(), 1);	//5��1��

	return 0;
}

//�ټ�9λ�޺�
static void do_jihe(CContainer * me, LONG param1, LONG step)
{
	CRoom * wuchang = load_room("���������䳡");
	char room_name[40];
	char msg[255];
	CRoom * r;
	CChar * monk;

	if(step == 10)
	{
		//ȫ���ټ����
		me->move(wuchang);
		tell_room(wuchang, "�����ʦ���˹�����");
        me->call_out(do_waiting, 1, 1);
		return;
	}
    
	snprintf(room_name, 40, "�������޺���%s��", chinese_number(step, msg));
    r = load_room(room_name);
  		
	if(! (monk = (CChar *)r->present(shaolin_xuan_ku_names[step - 1])) )
	{
		CContainer * env = load_room("�������޺����岿");
		me->move(env);
        tell_room(env, "�����ʦ���˹�����");
		tell_room(env, "�����ʦ˵�������ǶԲ����޺��������˲��ڣ��޷������޺�����");
		return;
	}

    tell_room(r, snprintf(msg, 255, "�����ʦ���˹�������%s��������˵�˼��䡣", monk->name()));
    monk->move(wuchang);
    tell_room(r, snprintf(msg, 255, "%s�޺����˵�ͷ���첽���˳�ȥ��", monk->name()));
	tell_room(wuchang, snprintf(msg, 255, "%s���˹�����", monk->name()));

	me->call_out(do_jihe, 1, param1, step + 1);	
}

static void do_waiting(CContainer * me, LONG wait_time, LONG param2)
{
	CContainer * r = me->environment();
	CChar * fighter;

	if( wait_time == 300 )
	{
		tell_room(r, "����˵�����������������ˣ����ǻ�ȥ�գ�");
		me->call_out(do_back, 1, 0);
		return;
	}

	if( ! (fighter = (CChar *)r->present(me->querystr("assigned_fighter")) ) )
	{
		me->call_out(do_waiting, 1, wait_time + 1);
		return;
	}

	if( ! r->present("xuannan dashi") || ! fighter->query_temp("xuannan_asked"))
	{
		if( random(10) == 0 ) 
			tell_room(r, "����˵����ȥ�������Ѵ�ʦû�У� ���������ڸõ��˰գ�");

		me->call_out(do_waiting, 1, wait_time + 1);
		return;
	}

	me->call_out(do_preparing, 1, fighter->object_id());
}
      
static void do_preparing(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = ob->environment();
	CChar * me = (CChar *)ob;
	CFightRoom * obj;
	CChar * fighter;
	CChar * monk;
	char msg[255];		

	//��鷿�����Ƿ���ս��
	while( (obj = (CFightRoom *)env->present("fight_room")) )
		obj->End_Fight();

	tell_room(env, "�����ʦ�������������޺������Χ��");
	tell_room(env, "ֻ����������ɳɳ�ĽŲ���������ʮ��λ�޺��Ǹ���������ɱ������ֿ�ȭ�����ֱֳ�����������Χ����������ס��ͨ·��");
	tell_room(env, "׼�����޺����󼴿̷�����");

	obj = (CFightRoom *)env->present("fight_room_18luohanzhen");
	if(! obj) 
	{
		fighter = (CChar *)env->Present(param1);
		if(! fighter)		//����Ѿ�ת�Ƴ���
		{
			me->call_out(do_back, 10);
			return;
		}
		
		me->command(snprintf(msg, 255, "chat 0 %s%s�ڽ�����ս����ʮ���޺�����", fighter->querystr("title"), fighter->name()));

		fighter->delete_temp("xuanku_asked");
		fighter->delete_temp("beat_count");
		
		obj = (CFightRoom *)load_item("fight_room");			//����ս������
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "ʮ���޺���", "fight_room_18luohanzhen");
		obj->move(env);
		fighter->move(obj);
		obj->Join_Team(fighter, CFightRoom::FIGHT_TEAM_B);
	}

	me->move(obj);
	for(int i=0; i<9; i++)
	{
		monk = (CChar *)env->present(shaolin_xuan_ku_names[i]);
		if(! monk)	//���޺�����
		{
			me->call_out(do_back, 10, 0);
			return;
		}
		monk->move(obj);
	}

	//ǰ���޺�����ս��
	monk = (CChar *)obj->present(shaolin_xuan_ku_names[0]);
	obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);

	obj->Begin_Fight(0);	//ս��
	me->call_out(do_fighting, 1, 1);	
}

static void do_back(CContainer * me, LONG step, LONG param2)
{
	char room_name[40];
	char msg[255];
	CRoom * r;
	CChar * monk;
	CContainer * env = me->environment();

	if(step == 10)
	{
		me->del("assigned_fighter");
		r = load_room("�������޺����岿");
		me->move(r);
		tell_room(r, "�����ʦ���˹�����");
		return;
	}

	if(! step)
		tell_room(env, "�����ʦ���˻��֣� �޺��ó������漴����뿪���䳡��");
	else
	{
       	snprintf(room_name, 40, "�������޺���%s��", chinese_number(step, msg));
	    r = load_room(room_name);

        if( (monk = (CChar *)env->present(shaolin_xuan_ku_names[step - 1]) ))
		{
	         monk->move(r);
			 tell_room(r, snprintf(msg, 255, "%s���˹�����", monk->name()));
		}
	}
	
	me->call_out(do_back, 1, step + 1);
}

static void do_fighting(CContainer * ob, LONG step, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CFightRoom * obj = NULL;

	if(EQUALSTR(env->querystr("base_name"), "fight_room") && EQUALSTR(env->querystr("name"), "ʮ���޺���"))
		obj = (CFightRoom *)env;

	if(! obj)
	{
		//�������Ƿ��Ѿ������޺�����
		CChar * fighter = (CChar *)env->present(me->querystr("assigned_fighter"));

		//�������л��������������Ҳ�����
		if(! fighter && step < 20)
		{
			me->call_out(do_fighting, 2, step + 1);
			return ;
		}

		if(! fighter || !living(fighter) || fighter->query_temp("beat_count") < 18)
		{
			if(fighter) 
				fighter->delete_temp("beat_count");

			me->say("�벻�� ... ����");
			g_Channel.do_emote(me, 0, "sigh", 0);
			me->call_out(do_back, 5);
			return;
		}
				
		me->call_out(do_recruit, 1, fighter->object_id());
		return;
	}

	if(step < 9)
	{
		CChar * monk = (CChar *)obj->present(shaolin_xuan_ku_names[step]);
		if(! monk || obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A))
		{
			//monk->set_temp("fight/wait_point", 1);	//�ú������ϳ���

			step++;
			tell_room(obj, "�޺������ٵ���ת�ţ�һ���������ս���");
		}
	}

	me->call_out(do_fighting, 1, step);	
}

static void do_recruit(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * fighter = (CChar *)(me->environment())->Present(param1);

	if(! fighter)
	{
		me->call_out(do_back, 5);
		return;
	}

	fighter->delete_temp("beat_count");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

	if (DIFFERSTR(fighter->querystr("family/family_name"), "������"))
	{
		g_Channel.do_emote(me, 0, "smile", 0);
		me->say("�˷����󣬵��Ա������д������棬�ٳ߸�ͷ������һ�������ľʹ˱����");
		me->call_out(do_back, 5);
	}
	else
	{
        me->say("��ϲ�㴳����ʮ���޺����� �����д˵Ƚܳ����ӣ���ʱ�ص�Ϊ���ַ�һ��ʣ�");
		me->call_out(do_back, 30);
	}
}


virtual void attempt_apprentice(CChar * me)
{   
	char msg[255];
	static char titles[9][10] = {
		"�����޺�",
		"�����޺�",
		"�ǻ��޺�",
		"�����޺�",
		"�̴�޺�",
		"�����޺�",
        "�����޺�",
        "�徻�޺�",
        "�����޺�",	
	};

	if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
	{
		say("���뱾��������������֪�˻��Ӻ�̸��", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "������")) 
	{
		say("�����׼ҵ��ӣ�����������ѧ�ա�", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("�⣬ƶɮ����ҵ� !", me);
		SendMenu(me);
		return;
	}

	char myname[5], prename[3];
	strncpy(myname, me->name(), 4)[4] = 0;
	strncpy(prename, myname, 2)[2] = 0;
	
	if ( ( me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "��") == 0)
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", snprintf(msg, 255, "�����޺������� %s", titles[random(9)]));
		me->UpdateMe();
	}

	if ( me->query("family/generation") == query("family/generation") + 2 )
	{
		if ( me->query("luohan_winner") )
		{
			say("���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !", me);

			char new_name[5];

			strcpy(new_name, "��");
			new_name[2] = myname[2];
			new_name[3] = myname[3];
			new_name[4] = 0;

			me->set_name( new_name);
			say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ������Ϊ�����ɳ��ֱ��޺�֮һ !", new_name));
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
			me->set("title", snprintf(msg, 255, "�����޺������� %s", titles[random(9)]));
			me->UpdateMe();
		}
		else
		{
			say("��û�д���ʮ���޺����󣬲���Խ����ʦ��", me);
			SendMenu(me);
			return;
		}
	}
}

NPC_END;