//xiaozhao.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_xiaozhao);

virtual void create()
{
	set_name("С��",  "xiao yi");
	set("nickname",  "����˼��������");
	set("long",  "��˫Ŀտտ������ü�˱ǣ��ձ�΢�����У������������ף�ֻ�������С�������δ���ɣ���Ȼ��ò������ȴ�ڲ�ס�����е�������");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon",girl1);
	set_weight(50000000);
	
	set("max_hp", 500);
	
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000 + random(10000));
	set("score", 20000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji_jian", 70);
	set_skill("taiji_quan", 70);
	set_skill("tiyunzong",50);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	
	set("party/party_name", "����");
	set("party/rank", "��˹ʥ����");
	set("party/level", 1);
	set("mj",1);
		
	set_inquiry("�˽�", ask_tuijiao);
	set_inquiry("���޵�", ask_wuji);
	set_inquiry("���콣", ask_jian);
	set_inquiry("�ƽ�", ask_gold);
	set_inquiry("ʳ��", "�Ե�����GG�뿪�ң����Ѿ�ʮ����û�Թ���ݮ�ˡ���");
	set_inquiry("��", ask_ge);
	//        set_inquiry("�����澭", ask_jiuyang);
	set_inquiry("Ǭ����Ų��", ask_qiankun);
	
	set("chat_chance", 3);
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(10000);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	static char msg[20][80]={
					"С�ǵ�������������˼�������� �䵱ɽ���ɰس�",
                    "С�ǵ����������������������� ����ɥ��������",
                    "С�ǵ���������������÷��ױ ��鶱��麣ãã",
                    "С�ǵ���������˭�ͱ��������� �ʮ�ط��麽",
                    "С�ǵ��������������ۻ���δ�� ��������ݸγ�",
                    "С�ǵ�����������Ů��������ǹ �������ҩ����",
                    "С�ǵ���������������������ǽ ����ʱ����ɽ��",
                    "С�ǵ�����������ı�����һ�� ���������ξ���",
                    "С�ǵ��������������ûһЦ�� ���쳤���ɺ�â",
                    "С�ǵ���������������ǽ�ƽ��� ���ӹ�Ѩ�����",
                    "С�ǵ������������ѽ�׵���ǿ Ⱥ�۹���Լ����",
                    "С�ǵ�����������ܽ�������ׯ ̫��������˸�",
                    "С�ǵ����������ٻ�����λͻ� ��ò���������",
                    "С�ǵ����������ٳ߸����λ��� �������������",
                    "С�ǵ�����������Ůͬ�ۺ����� �������������",
                    "С�ǵ���������������ʧ������ ԩ�ɲ��׳�����",
                    "С�ǵ����������ﳤ�ٶ������� �¸������Ѻ���",
                    "С�ǵ�����������ʨ�л���Ϊ�� ز�����������",
                    "С�ǵ�������������Ӣ��Ī�ܵ� ���ӿ���֮�Է�",
                    "С�ǵ������������ű�����в� ��ʶ����������",
	};

	return msg[random(20)];
}

static char * ask_tuijiao(CNpc * me, CChar * who)
{
        if(DIFFERSTR(who->querystr("party/party_name"), "����"))
            return "С��ݸ��һЦ������˵�����㻹û�����������أ������˽̣�";
            
        if(EQUALSTR(who->querystr("family/family_name"), "����") )
        	return "С��̧��������$N˵�������Ѿ�����ʥ�̵��ӣ�������˽̣�";
        
        me->say(g_Channel.do_emote(me, who, "sigh", 1), who);
        me->say(g_Channel.do_emote(me, who, "shake", 1), who);
		me->SendMenu(who);
        who->del("party");
        who->del("rank");
        who->del("mjlevel");
        return 0;
}

static char * ask_wuji(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, "sigh", 1), who);
        me->say("С�����ĵ�˵������˼����������������������̡�", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_jian(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, ":P", 1), who);
        me->say("���а��������Ź������ұ��ܵģ����������ˡ�", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_gold(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, ":P", 1), who);
        me->say("���а����ⲻ�������ˡ�", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_ge(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, "nod", 1), who);
        me->say("С����������������������  ����������", who);
        me->say("С���������������˼�������˷�  ������ �ײؼ�  �������ܳ�����", who);
        me->say("С��������������ӯ�  ������ʴ  ���¶���  �������  �����������", who);
        me->say("С������������չ�ų�ü  ��������  ��������  ��������  ��������  �������", who);
        me->say("С�����������������͵��޵�  ƶ�ĺ͸���  ��ͷ��һ��  ������һ��", who);
        me->say("С������������������һ��  һ������", who);
        me->say("С�������������������  ��ʮ��ϡ  ��������  ������ˮ", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_qiankun(CNpc * me, CChar * who)
{
        if (who->query_temp("mark/qiankun") &&
				EQUALSTR(who->querystr("party/party_name"), "����"))
        {
            who->delete_temp("mark/qiankun");
			return "С��ݸ��һЦ������˵����Ǭ����Ų���ķ��ڱ����ܵ����Ե�Ļ������ҵ���";
        }
        		
		who->set_temp("mark/qiankun", 1);
        return "���ϴ���������������ʧ�٣�Ǭ����Ų���ķ��Ѿ�ʧ��ܾ��ˡ�";
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("id"), "qiankun_fake"))
	{
		who->set_temp("qiankun_fake", 1);
		message_vision("$N������������������ҵ��ģ�", this);
		AddMenuItem("������Ƥ��ʲô�ر�", "$0surprise $1", who);
		SendMenu(who);

		destruct(ob);
		return 1;
	}
	else if ( DIFFERSTR(ob->querystr("id"), "caomei") || DIFFERSTR(ob->querystr("name"), "��ݮ") )
	{	
		message_vision("$N΢Ц�ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "lianyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "surprise") == 0)
	{
		return do_surprise(me);
	}
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

int do_surprise(CChar * me)
{
	if(! me->query_temp("qiankun_fake")) return 0;

	me->delete_temp("qiankun_fake");

	message_vision("$N�ͳ�һ��С�����������ָ����ѪĨ����Ƥ���档", this);
	if(random(10) < 6)
	{
		me->receive_damage("hp", me->query("hp")/10);
		message_vision ("$Nʹ������ֱ��������������Ƥȴʲô��Ӧ��û�С�", me);
		return 0;
	}
	else
	{
		me->receive_damage("hp", me->query("hp")/10);
        load_item("qiankun_xinfa")->move(me);
		SendMenu(me);
		message_vision ("$N����Ѫ����Ƥ�ϻ������������Գ�һЩ�ּ�����", me);
		return 0;
	}
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
				snprintf(msg, 255, "$HIY%s$HIC�����湦��ն������$HIY��˹�ܽ���%s$HIC��",me->name(1),this->name(1)));

		}
	}
	CNpc::die();
}
NPC_END;




