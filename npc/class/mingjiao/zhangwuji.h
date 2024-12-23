//zhangwuji.h
//Lanwood 2000-01-09
//�޸ģ�����������

ZUSHI_BEGIN(CNmingjiao_zhangwuji);

virtual void create()
{
	set_name("���޵�",  "zhang wudi");
	set("long", "���̽������޵У�ͳ������ʮ����ڣ��������ƣ�߳��ǧ��������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�����������Ӣ�ۡ�");
    set("title","���̵���ʮ�Ĵ�����");
	set("gender", "����");
    set("age", 20);
	set("shen_type",1);
//	set("attitude", "friendly");
	set("icon",young_man4);
	set_weight(50000000);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 12000);
    set("max_hp", 12000);
    
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 120);

    set("combat_exp", 17000000);
    set("score", 455000);
    
    set_skill("force", 330);
    set_skill("dodge", 280);
    set_skill("parry", 280);
	set_skill("unarmed", 300);
    set_skill("jiuyang_shengong", 330);
	set_skill("lingfa", 300);
	set_skill("shenghuo_lingfa", 300);
	set_skill("qiankun_danuoyi", 300);
	set_skill("shenghuo_xinfa", 280);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");

    create_family("����",34, "����");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
//	prepare_skill("lingfa", "shenghuo_lingfa");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

	set("apply/armor", 100);
    set("apply/damage", 100);
	set("no_chan",1);
	set("shen_type", 1);

	carry_object("shenghuo_ling")->wield();
    carry_object("baipao")->wear();
	set("no_talk",1);
	set("no_huan",1);
	
};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("was/renwu2_1") && !me->query_temp("was/renwu2_2") )
	{
		AddMenuItem("�����޵�ѯ���й�Ӫ����������", "$0liupai $1", me);
		SendMenu(me);
		me->set_temp("was/renwu2_11",1);
		return 1;
	}
	if(EQUALSTR(me->querystr("party/party_name"), "����"))
	{
		if(strcmp(ask, "����") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}

		me->set_temp("pending/jiaozhu", 1);
		AddMenuItem("�����ѯ��Ǭ����Ų��", "$0qiankun $1", me);
		AddMenuItem("�������Ҫ������", "$0tieyan $1", me);
		AddMenuItem("�������������֮λ", "����", me);
		AddMenuItem("�������ȡ����������", "$0hujiao $1", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("was/renwu2_11"))
	{
		if(me->query_temp("was/renwu2_1") && !me->query_temp("was/renwu2_2") )
		{
			CContainer * linpai=me->present("lei ting lin");
			if(!strcmp(comm, "liupai") 
				&& linpai && EQUALSTR(linpai->querystr("owner"),me->id(1)))
			{
				say("���޵У���������֪�������ɵĸ��ֶ�����ʮ�����ɢ�Ķ��ұ����������ڡ����µ�����ʮ�����أ�������ɽ��׼���˳���ǰ������",me);
				me->set_temp("was/renwu2_2",1);//��ȡ����һ���ι۹���Ʊ
				CContainer * obj = load_item("baozi");
				obj->set_name("����һ���ι۹���Ʊ","guan guang piao");
				obj->set("long","����һ�ű�����ֽƬ������д�š�����һ���ι۹���Ʊ����������");
				obj->set("owner",me->id(1));
				obj->set("was/menpiao",1);
				obj -> move(me);
				tell_object(me, "���޵и�������1��$HIC������һ���ι۹���Ʊ��$COM��");
			}
			else
				say("���޵У���������Щʲô������",me);
			SendMenu(me);
			return 1;
		}
	}
	if(me->query_temp("pending/jiaozhu"))
	{
		if(strcmp(comm, "qiankun") == 0)
			return do_qiankun(me);
		if(strcmp(comm, "tieyan") == 0)
			return do_tieyan(me);
		if(strcmp(comm, "hujiao") == 0)
			return do_hujiao(me);
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
	return CNzushi::handle_action(comm, me, arg);
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
	switch(random(3))
	{
	case 0:
			perform_action("lingfa duo", 1);
			break;
	case 1:
			perform_action("lingfa xiyanling", 1);
			break;
	case 2:
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
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who ) return;

	if( who->query("repute")<-5000)
	{
		me->say("ħ����������ѧ������������Ȱ���������������سɷ�.");
	}
	else if(who->query("repute")<-100)
	{
		me->say("��λ���ѣ����н��������е����������߽�аħ���.");
	}
	else if(who->query("repute")>=0)
	{
		me->say("�������������ߣ�Ȱ����ӱ���.");
	}
	else if(who->query("repute")>20000)
	{
		me->say("�������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳�.");
	}

	return;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"), "����"))
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

	if(me->query_int() < 30)
	{
		say("�������̫���ˣ����ʺ�ѧϰ�ҵĹ���", me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("force", 1) < 150)
	{
		say("��Ļ����ڹ�̫���ˣ�ѧϰ�ҵĹ�����˼�����", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") < 30000)
	{
		say("��Ӧ������Щ����������£��������ġ�", me);
		SendMenu(me);
		return;
	}

	if(me->query("party/level") < 5)
	{
		say("�����ʱ���ж̣��������������������������ͬ�⣬�һῼ��������ġ�", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
        
	me->set("party/level", 6);
	me->set("title", "���̽����״�����");
	say("�ã��Ҿ���������λ���ֵ�", me);
	say("�ٽ����£�", me);
	SendMenu(me);
	return;
}

/*
int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣���ȥ�ɡ�\n",ob);
        return 0;
    }
    message_vision("���޼�һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);
    return 1;
}
*/

int do_qiankun(CChar * me)
{
	if(me->query_skill("shenghuo_xinfa",1)<100)
	{
		say("��ʥ���ķ���Ϊ��������", me);
		SendMenu(me);
		return 1;
	}
	
	if(me->query_combat_exp() < 800000) 
	{
		say("��ʵս���黹������", me);
		SendMenu(me);
		return 1;
	}
	
	if(me->query_skill("force",1)<100) 
	{
		say("�ƺ������ڹ���Ϊ��������", me);
		SendMenu(me);
		return 1;
	}
	
	if ( me->query_temp("marks/Ų��") ) 
	{
	   say("�㲻�Ǹող��ʹ���", me);
	   SendMenu(me);
	   return 1;
	}
	
	say("�ðɣ��Ҿ�׼���������������Ǭ����Ų�ơ��Ժ���Ҫ���������̡�", me);
	say("�ص��������̳����ʯ���8����ϸ��һ�Ҿ��ܿ����ˡ�", me);
	say(g_Channel.do_emote(me, me, "pat", 1), me);
	say(g_Channel.do_emote(me, me, "addoil", 1), me);
	SendMenu(me);
				
	me->set_temp("marks/Ų��", 1);	
	return 1;
}

int do_tieyan(CChar * me)
{
	if(query("have_given"))
	{
		say("�������ˣ��������Ѿ������ˡ�", me);
		SendMenu(me);
		return 1;
	}

	load_item("tieyanling")->move(me);
	say("�ܺã��������������ȥ��ս�ɡ�", me);
	SendMenu(me);
	set("have_given", 1);
	call_out(do_reset, 180);

	return 1;
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->del("have_given");
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
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if(DIFFERSTR(ob->querystr("name"), "������") )	return 0;
	destruct(ob);
	if (EQUALSTR(who->querystr("party/party_name"), "����")) 
	{
		int exp=(random(100)+10)*who->query("level");
		who->add("combat_exp", exp);
		tell_object(who, snprintf(msg, 255, "$HIY�㻤���й�����������%ld�㾭�飡", exp));
	}
	return 1;
}
*/

int do_hujiao(CChar * player)
{	
	char msg[255];
	CContainer * bot;
	CContainer * env = load_room("pk");
	if(env->query("mjok"))
	{
		if(player->query_temp("mj/exp"))
		{
			int exp=player->query_temp("mj/exp");
			if(exp>800)
			{
				player->set("xkd/mingjiao",1);
				CContainer * r = load_room("���̴��");
				if(EQUALSTR(player->querystr("family/family_name"), "����") && r->query_temp("lin_count"))
				{
					tell_object(player, "���޵�˵��:�㻤���й������ʥ������͸���ɣ�����������Щ�������г�����һЩʹ���ĵã�ϣ������Ժú���ϧ��");
					bot = load_item("shenghuo_lingpro");
					bot->set("skill/name","lingfa");	
					bot->set("skill/exp_required",  50000);	
					bot->set("skill/jing_cost",40);	
					bot->set("skill/difficulty", 50 );	
					bot->set("skill/max_skill",  400);	
					bot->set("skill/min_skill", 300 );
					if(player->query("����")>=10 && !(player->query("����")%10))
						bot->set("kill",player->query("����")/10);
					bot->set("owner",player->id(1));  
					bot->move(player);
					player->set("mj/linfa",400);
					r->add_temp("lin_count",-1);
				}
				else
				{
					tell_object(player, "���޵�˵��:�㻤���й������˲��ٽ��е��ֵ��ǣ���ϧ�ҵĶ����Ѿ�ȫ�����ˡ���");
					int exp=(random(40)+50)*player->query("level");
					player->add("combat_exp", exp);
					tell_object(player, snprintf(msg, 255, "$HIY���޵д�������%ld���ʵս���飡", exp));
				}
				if(exp>900)
				{
					player->add("����",1);
					message_vision("\n$HIR$N�Ľ�������������һ�㣡\n", player);
				}
			}
			else if(exp>700)
			{
				tell_object(player, "���޵�˵����$HIY�㻤���й���������ţ����ȥ�콱��ȥ�ɣ�");
				player->set_temp("mj/����ţ",1);
			}
			else if(exp>600)
			{
				if(random(3))
				{
					tell_object(player, "���޵�˵����$HIY�㻤���й�����ӥ������ȥ�콱��ȥ�ɣ�");
					player->set_temp("mj/ӥ��",1);
				}
				else
				{
					tell_object(player, "���޵�˵����$HIY�㻤���й�������ʹ����ȥ�콱��ȥ�ɣ�");
					player->set_temp("mj/��ʹ",1);
				}
			}
			else if(exp>400)
			{
				tell_object(player, "���޵�˵����$HIY�㻤���й�������������ȥ�콱��ȥ�ɣ�");
				player->set_temp("mj/����",1);
			}
			else if(exp>200)
			{
				if(random(3))
				{
					tell_object(player, "���޵�˵����$HIY�㻤���й�������ʹ����ȥ�콱��ȥ�ɣ�");
					player->set_temp("mj/��ʹ",1);
				}
				else
				{
					tell_object(player, "���޵�˵����$HIY�㻤���й�����ʨ������ȥ�콱��ȥ�ɣ�");
					player->set_temp("mj/ʨ��",1);					
				}
			}
			else if(exp>100)
			{
				tell_object(player, "���޵�˵����$HIY�㻤���й�������������ȥ�콱��ȥ�ɣ�");
				player->set_temp("mj/����",1);
			}
			exp=exp*(random(6)+5)*(1+random(10)/10);
			player->add("combat_exp", exp);
			int repute=random(int(exp/2))+exp;
			if(player->query("repute")<0)
				repute=-repute;
			player->add("repute",repute);
			tell_object(player, snprintf(msg, 255, "$HIY�㻤���й���������������%ld��ʵս���飬ͬʱ�����%d��Ľ���������", exp,repute));
			player->delete_temp("mj/exp");
		}
		else
			tell_object(player, "���޵�������üͷ��˵������е�ǰ֮ʱ����ȥ��ʲôȥ�ˣ���");
	}
	else
		tell_object(player, "���޵�˵����ʲô����");
    return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "���̴��" ))
		return notify_fail("�����������");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;




