//hu.h
//lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_hu);

virtual void create()
{
	set_name("����ţ", "hu tieniu");
	set("long","���������̺ųƼ������ȵĺ���ţ����˵����ͨҽ���������������������Ӳ�ҽ������ʿ��");
	set("gender", "����");
	set("title", "���̽���");
	set("nickname","����ҽ��");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5);
	set_weight(50000000);
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);
	
	create_family("����", 35, "����");
	
	carry_object("cloth")->wear();
	set_inquiry("����",ask_me);
	set_inquiry("��������",ask_hujiao);
}

static char * ask_me(CNpc *who,CChar *me)
{
	char msg[80];
	if (DIFFERSTR(me->querystr("party/party_name"), "����"))
		return "�㲻�����������µ��ӣ��Ҳ�����Ϊ�����ˡ�";
	if ( me->query("eff_hp") == me->query("max_hp"))
	{
		who->command(snprintf(msg,80,"? %ld",me->object_id() ));     
		who->say(" ��û�����κ��˰���");
	}
	else
	{
		message_vision("����ţι$N����һ��ҩ��,Ȼ����ϥ���£�˫������$N�ı��ġ�", me);
		who->remove_call_out(recover);
		who->call_out(recover,2,me->object_id() );
	}
	return "";
}

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("�����һ����Ʒ�");
	CContainer * bot;
	if(me->query_temp("mj/����ţ"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "����") && r->query_temp("dan_count"))
		{
			tell_object(me, "����ţ˵��:��λ�����������٣����˲��ٽ��е��ֵ��ǣ�");
			tell_object(me, "�������и����Ƴ�����һ����ҩ������������֮Ч���͸���һ�Űɣ�");
			bot = load_item("baomingdan");
			bot->move(me);
			r->add_temp("dan_count",-1);
		}
		else
		{
			tell_object(me, "����ţ˵��:��λ�����������٣����˲��ٽ��е��ֵ��ǣ���ϧ�������Ƴ�����ҩ�Ѿ�ȫ�������ˡ���");
			int exp=(random(30)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY����ţ��������%ld���ʵս���飡", exp));
		}
		me->delete_temp("mj/����ţ");
	}
	else
		tell_object(me, "����ţ��ʲô����");
	return "";
}

static void recover(CContainer *ob,LONG param1,LONG param2)
{
	CChar * me=(CChar *)(ob->environment())->Present(param1);
	if (!me) return;

	me->set("eff_hp",  me->query("max_hp"));
	me->FlushMyInfo();
	message_vision("��Լ����һ�Ѳ��ʱ�ݣ�����ţ������վ��������",me);
	message_vision("����ţ˵������������Ѿ�ȫ����,����������", me);
	return ;
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
	return CNpc::handle_action(comm, me, arg);
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
				snprintf(msg, 255, "$HIY%s$HIC�����湦��ն������ħͷ$HIY%s$HIC��",me->name(1),this->name(1)));
		}
	}
	CNpc::die();
}
NPC_END;



