//zhang.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

SHENLONG_BEGIN(CNshenlong_zhang);

virtual void create()
{
	set_name("�ŵ���","zhang danren");
	set("title", "�����̺���ʹ");
	set("long", "����һ�����´�, ��ɫ���, ���ӷ���, �ƺ��־��Ѽ�." );
	set("gender", "����");
	set("icon",young_man1);	

	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);
	set("max_hp", 9000);
    set("hp",3000);
	set("max_mp",1000);
    set("mp",1000);
	set("mp_factor", 50);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("unarmed", 100);
    set_skill("strike", 90);
    set_skill("parry", 100);
    set_skill("staff", 90);
    set_skill("sword", 90);
	set_skill("literate", 90);
	
	set_skill("shenlong_xinfa", 90);
	set_skill("yixingbu", 90);
	set_skill("shenlong_bashi", 90);
	set_skill("huagu_mianzhang", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("������",2,"����");
	set("chat_chance_combat", 30);

    set_inquiry("���",do_join);
	set_inquiry("�鰲˳","����Ƣ������,Ҫ�������Ĳź�");
	set_inquiry("����","����Ƣ������,Ҫ�������Ĳźá�");
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ!");

    carry_object("duanjian")->wield();
	add_money(1000);
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("baihua"))
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return "";
}

static char * do_join(CNpc * npc , CChar * player)
{
	if (player->query("repute") > 0)
	{
		message_vision("$N��$n��ŭ����������̣�һ����Ͳ��Ǻ���! ", npc, player);
		npc->kill_ob(player);
		return 0;
	}

	if(player->querymap("party") && DIFFERSTR(player->querystr("party/party_name"), "������"))
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ����������������̡�", npc, player);
		return 0;
	}

	if(player->query("age") > 24)
	{
		message_vision("$N���ε�ҡҡͷ��$n˵����������ֻϲ������������Ů�����ޱ�����Ե����", npc, player);
		return 0;
	}

	if( EQUALSTR(player->querystr("party/party_name"), "������") )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ����������̵����ˡ�",npc, player);
		return 0;
	}

	char new_rank[40];
	snprintf(new_rank, 40, "����ʹ����");
	player->set("party/party_name","������");
	player->set("party/rank", new_rank);
	player->set("party/level", 1);
	
	g_Channel.do_emote(npc,player, "smile", 0);
	message_vision("$N��$n˵���������ʱ�ڱ�ʹ����Ч���ɣ�",npc,player);
	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "������"))
	{
		say("�㲻�Ǳ��̽���, ����������!",player);
		SendMenu(player);
		return;
	}
	if (player->query("repute") > 0  ) 
	{
		say("�������������������������������ְ׵�����򽻵�������ذɣ�",player);
		SendMenu(player);
		return;
	}

	say("�ܺã��ܺá�");
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

NPC_END;