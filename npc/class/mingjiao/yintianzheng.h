//yintianzheng.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_yintianzheng);

virtual void create()
{
	set_name("�����", "yin tiangang");
	set("long",  "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�����üʤѩ�������۽ǣ����ӹ���������ӥ�졣");
	                                                         
	set("title", "��üӥ��");
	set("mjlevel",9);
	set("gender", "����");
	set("attitude", "peaceful");
	set("icon",old_man2);
	set_weight(50000000);

	CMapping par;

	par.set("level", 5);
	set("party", par);

	set("age", 72);
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
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("force", 250);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("claw", 300);

	set_skill("sougu", 250);
	set_skill("shenghuo_shengong", 200);
	set_skill("shenghuo_xinfa", 200);
	set_skill("piaoyibu", 150);
	set_skill("literate", 120);

	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("claw", "sougu");
	map_skill("parry", "sougu");
	prepare_skill("claw","sougu");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
	
    create_family("����",35, "����");
	
//    set_inquiry("����", ask_me);
	carry_object("baipao")->wear();
	set_inquiry("��������",ask_hujiao);
	set("no_huan",1);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("���̴��");
	if(me->query_temp("mj/ӥ��"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "����") && r->query_temp("yingwang_count"))
		{
			tell_object(me, "�����˵��:��δ�ս�������С�ֵ����ˡ�������������������������");
			tell_object(me, "�㰴��ӥ������ʾ���ڵ��ϣ������Ҳ��ϥ������ı��󣬻���������������ı���...");
			tell_object(me, "��Ȼ����ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...");
			me->start_busy(50);
			me->add("max_mp",random(10)+10);
			r->add_temp("yingwang_count",-1);
			tell_object(me, "$HIR����ӥ����Э���£�ͻ����������������ޡ�");
			me->UpdateMe();
		}
		else
		{
			tell_object(me, "�����˵��:��δ�ս�������С�ֵ�����˲��ٽ��е��ֵ��ǣ���ϧ����������û�лָ���ȫ...");
			int exp=(random(25)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY�����������%ld���ʵս���飡", exp));
		}
		me->delete_temp("mj/ӥ��");
	}
	else
		tell_object(me, "�����ʲô����");
	return "";
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("force heal", 0);
		break;
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("claw muye", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) &&  !is_fighting())
	{
		if(me->query_temp("marks/����2")) 
		{ 
			call_out(do_back, 1);
		}
        
		if ((DIFFERSTR(me->querystr("party/party_name"), "����"))) 
		{
		    remove_call_out(do_killing);
            call_out(do_killing, 4, me->object_id());
		}
	}
}

static void do_killing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who ) return;

	g_Channel.do_emote(me, who, "consider", 0);
    me->kill_ob(who);
	return;
}

static char * ask_me(CNpc * me, CChar * who)
{
	if ( who->query_temp("marks/����1") ) 
	    return "������뻤�̾��˳��ɡ�";
	
	if ( who->query_combat_exp() > 50000)  
		return "���书��ǿ��������Щ�¾��������������ɡ�";
	
    if ( who->query_temp("marks/����3") ) 
		return "����û��������ɸ��㣬��Ϣ��Ϣ�����ɡ�";
	
	who->set_temp("marks/����1", 1);
	who->call_out(do_hujiao, 150);
	return "��������ȱ�����֣���͵�ɽ����ȥ���̰ɡ��Է�������͵Ϯ��������";
}

static void do_hujiao(CContainer * ob, LONG param1, LONG param2)
{ 
	tell_object((CChar *)ob, "��Ļ���ʱ�䵽�ˣ��û�ȥ�����ˡ�");
	ob->set_temp("marks/����2", 1);
}

static void do_back(CContainer * ob, LONG param1, LONG param2)
{  
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	if ( who->query_temp("marks/����ok") ) 
	{
		me->say(snprintf(msg, 255, "%s�ɵúã��Ϸ�û��ʲô������ģ��ͽ���һЩʵս����ɡ�", who->name()));
 		who->add("combat_exp", 140 + random(80));
		who->delete_temp("marks/����2");
		who->delete_temp("marks/����ok");
		who->delete_temp("marks/����1");
		who->set_temp("marks/����3", 1);
		who->call_out(do_waiting, 50);
		return;
	}
	else     	
	{
		me->say("�������û�вμӻ��̣�������ʲô������");
		who->delete_temp("marks/����2");
		who->delete_temp("marks/����1");
		who->call_out(do_waiting, 50);
		return;
	}
}

static void do_waiting(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("marks/����3");
	ob->delete_temp("marks/����1");
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"),"����"))
	{
		say("���Ѿ������������ɣ���ذɡ�", me);
		SendMenu(me);
		return;
	}
	if(DIFFERSTR(me->querystr("party/party_name"), "����"))//���Ĳ���
	{
		say("�����뱾��������������ذɡ�", me);
		SendMenu(me);
		return;
	}
	if(me->query_skill("force", 1) < 100)
	{
		say("��Ļ����ڹ�̫���ˣ�ѧϰ�书Ҫ�ȴ�û�����", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") <= 10000)
	{
		say("Ӧ������Щ����������£��������ġ�", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") > 4)
	{
		say("�����ڽ��еĵ�λ����������ҵ�!", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") <= 3)
	{
		say("����δͨ���������ԣ�û���������Ƽ��ţ���������Խ����ͽ��", me);
		SendMenu(me);
		return;
	}
	else if(me->query("family/generation") == query("family/generation") + 1)//ʦ�����NPCͬ��
		say(snprintf(msg, 80, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
	else
	{
		say("�ã��Ҿ���������λ���ֵ�", me);
		SendMenu(me);
	}
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("title", snprintf(msg, 80, "%s�״�����", querystr("title")));
	me->UpdateMe();
	return;
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if (EQUALSTR(obj->querystr("id"), "tuijian xin4" )
		&& me->query_temp("have_letter") )
	{
		me->set_temp("apprentice_ok",1);
		destruct(obj);
	    say("�ã���Ը����뱾����������");
		AddMenuItem("Ը�����", "$0join $1", me);
		AddMenuItem("��ʱ����", "", me);
		SendMenu(me);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "?", 1), me);
    say("�ⶫ�����ҿ�û��ʲ���á�", me);
	SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);

	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n��üŭ��$N���޵����������е�ǰ֮�ʣ��㵽������ʲô������", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_join(CChar * me)
{
	char msg[255];

	if ( me->query("party/level") >= query("party/level") )
	{
        say("��������ҵ� !", me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("party/level") == 3 )
	{
		me->delete_temp("have_letter");
		me->delete_temp("apprentice_ok");
	
		char title[10], new_rank[40];
		strncpy(title, querystr("title"), 8)[8] = 0;
		snprintf(new_rank, 40, "%s���»���", title);
		me->set("party/rank", new_rank);
		me->set("party/level", 4);
		
		say("������ !", me);
        say("�����ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !", me);
	    say(snprintf(msg, 255, "��ϲ������Ϊ����%s��", new_rank), me);
		SendMenu(me);	
	}
	
	return 1;
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC�����湦��ն������ħͷ$HIY%s%s$HIC��",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
NPC_END;




