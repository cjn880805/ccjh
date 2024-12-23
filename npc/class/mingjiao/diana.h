//diana.h
//Cat
//2001-02-27
//��������

NPC_BEGIN(CNmingjiao_diana);

virtual void create()
{
	set_name("�찲��", "diana");
	set("long", "�����Ĵ���֮һ����˵�����ʱ���൱Ư����һ�ֶ����������ǿ��ž���\n");
 
	set("title","��������");
	set("mjlevel",9);
	set("gender", "Ů��");
    set("age", 45);
    set("attitude", "friendly");
	set("icon",old_woman);
	set_weight(50000000);

	CMapping par;

	par.set("level", 5);
	set("party", par);

	set("age", 42);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 10500);
	set("max_hp", 10500);
	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 150);
	set("combat_exp", 1350000);
	set("score", 50000);
    
    set_skill("force", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
	set_skill("unarmed", 200);
    set_skill("throwing", 280);
	set_skill("finger", 150);

    set_skill("shenghuo_shengong", 200);
	set_skill("xuantian_shengong", 200);
	set_skill("xuantian_zhi", 300);
	set_skill("shenghuo_xinfa", 200);
	set_skill("duoming_jinhua", 280);
	set_skill("piaoyibu", 200);
	set_skill("literate", 120);

	map_skill("parry", "duoming_jinhua");
	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("throwing", "duoming_jinhua");
	map_skill("finger", "xuantian_zhi");
	prepare_skill("finger", "xuantian_zhi");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

    create_family("����",35, "����");
	
	carry_object("baipao")->wear();
	carry_object("jinhua", 300)->wield();

	set_temp("have_hua", 20);
	set_inquiry("��������", ask_hua);
	set_inquiry("��������",ask_hujiao);
	set("no_huan",1);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("���̴��");
	if(me->query_temp("mj/����"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "����") && r->query_temp("longwang_count"))
		{
			tell_object(me, "�찲��˵��:��л����������������������ҽ̲����ֵܣ�");
			tell_object(me, "�ҿ������ʲ���������һ�����Լ����г����ġ������ȷ������ʹ�����ɣ�");
			me->set_skill("youlong_staff",me->query_skill("youlong_staff", 1)+1);
			me->add("mj/youlong_staff",1);
			me->add("mj/skill_count",1);
			me->FlushMySkill(me);
			if(!me->query("mj/youlong_staff"))
				me->set(snprintf(msg, 255, "mj/skill%d",me->query("skill_count")),"youlong_staff");
			r->add_temp("longwang_count",-1);
		}
		else
		{
			tell_object(me, "�찲��˵��:��л����������������������ҽ̲����ֵܣ�");
			tell_object(me, "��������������Ļ����Ҿʹ�����һЩʵս����ɣ�");
			int exp=(random(20)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY�찲�ȴ�������%ld���ʵս���飡", exp));
		}
		me->delete_temp("mj/����");
	}
	else
		tell_object(me, "�찲�ȣ�ʲô����");
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
			perform_action("throwing huayu", 1);
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
		if (DIFFERSTR(me->querystr("party/party_name"), "����"))  
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

	if( EQUALSTR(obj->querystr("id"), "tieyan ling")
		&& EQUALSTR(me->querystr("party/party_name"), "����")
		&& me->query("party/level") == 4
		&& !me->query_temp("have_letter") ) 
	{
		me->set_temp("fight_ok",1);
		destruct(obj);
		say("�ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��", me);
		AddMenuItem("��ʼ����", "$0bishi $1", me);
		AddMenuItem("ת���뿪", "", me);
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

	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "�������Ի�");
		carry_object("jinhua", 100)->wield();
		return 1;
	}
	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);

	return CNpc::handle_action(comm, me, arg);
}

virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok"))	return;

		winner->delete_temp("fight_ok");
        say("������ʤ����������������̵ļѵ��� ! ��ϲ���� !");
        say("�������Ѿ����ҽ̻��̷���֮һ�� !");

		char new_rank[40];
		snprintf(new_rank, 40, "���̷���");
		winner->set("party/rank", new_rank);
		winner->set("party/level", 5);
		return;
	}
	
	say("�����㻹�ö����ϰ�������������������г���ͷ�� !");
	return;	
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

static char * ask_hua(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "����") && DIFFERSTR(player->querystr("family/master_id"), "diana"))	//ԭΪ��Ĺ��,��Ϊ���� lanwood 2001-05-25
		return "�㲻�������´��ˣ�����������";
	if(player->query_temp("mark/get_hua"))
		return "�㲻�Ǹ��ù��𣿲�Ҫ��ô̰�ĺò��ã�";
	if(npc->query("have_hua") < 0)
		return "�������ˣ������Ѹ���������ͬ���ˡ�";

	load_item("jinhua")->move(player);
	load_item("jinhua")->move(player);
	load_item("jinhua")->move(player);

	player->set_temp("mark/get_hua",1);
	npc->add_temp("have_hua", -1);

	message_vision("�찲�ȸ���$Nһ�Ѷ���������", player);
	return "";
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




