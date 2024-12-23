//su.h
//code by zwb
//12-16
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshenlong_su);

virtual void create()
{
	set_name("����","su quan");
	set("title",  "�����̽�������" );
	set("long", "�����������̽����鰲ͨ�ķ��ˡ�");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("icon",young_man2);	
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 400000);

    set_skill("force", 180);
    set_skill("dodge", 180);
    set_skill("unarmed", 180);
    set_skill("strike", 150);
    set_skill("parry", 180);
    set_skill("staff", 150);
    set_skill("sword", 150);
	set_skill("literate", 120);
	
	set_skill("shenlong_xinfa", 160);
	set_skill("yixingbu", 160);
	set_skill("shenlong_bashi", 160);
	set_skill("huagu_mianzhang", 160);
	set_skill("shedao_qigong", 160);

	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("������",2,"����");

    set_inquiry("������","һ�������벻���������̵�.");
	set_inquiry("�˽�",ask_tuijiao );
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ!");

	carry_object("cloth")->wear();
	carry_object("duanjian")->wear();
	add_money(10000);

	set("chat_chance_combat", 10);
}

virtual char * chat_msg_combat()
{
	
	if(!query_temp("wei/renwu4_1"))
	{
		switch(random(5))
		{
		case 0:
			return "���ò��ͷ�����������";
		case 1:
			perform_action("sword chang", 1);
			break;
		case 2:
			perform_action("sword chang2", 1);
			break;
		case 3:
			perform_action("sword chang3", 1);
			break;
		case 4:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		tell_room(environment(), "����Ż����ŵ��뿪��ս����");
		CFightRoom * obj=(CFightRoom *)environment();
		obj->End_Fight();
	}

	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "������") ) 
	{
		say("�㲻�Ǳ��̽���, ����������!",player);
		SendMenu(player);
		return;
	}

	if (DIFFERSTR(player->querystr("gender"), "Ů��"))
	{
		say("������ϲ�������е��ӵġ�",player);
		SendMenu(player);
		return;
	}

	if (player->query_skill("shenlong_xinfa",1) < 60 ) 
	{
		say ("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°�!",player);
		SendMenu(player);
		return;
	}

	if(player->query_skill("shedao_qigong",1) < 60 ) 
	{
		say(" ��ı����湦̫���ˣ�����ŬŬ�������һ�°�!",player);
		SendMenu(player);
		return;
	}

	if (player->query("repute") > -10000  ) 
	{
		say(" �������������������������������ְ׵�����򽻵�������ذɣ�",player);
		SendMenu(player);
		return;
	}

	say(" �ܺã��ܺá�");
	SendMenu(player);
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

static char * ask_tuijiao(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "������") )
	{
		return "����ݸ��һЦ������˵�����㻹û�������������أ������˽̣�";            
	}
	
	if( EQUALSTR(player->querystr("family/family_name"), "������" ))
	{
		return "���������������˵�������Ѿ������������ӣ�������˽̣�";            
	}
	
	npc->say(g_Channel.do_emote(npc,player, "sigh", 1), player);
	npc->say(g_Channel.do_emote(npc,player, "nod", 1), player);
	npc->say("�����㲻Ҫײ��������! ",player);
	npc->SendMenu(player);
	
	player->del("party");
	// player->del("rank");
	//  player->del("level");
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!query("ok"))
	{
		if(me->query_temp("wei/renwu4_8"))
		{
			say("����̾�˿������������£����ǷǷǣ���������Ļ����䣡�������������С�����ȥ�ɣ���",me);
			SendMenu(me);
			return 1;
		}
		else if(me->query("wei/renwu1") && !me->query("wei/renwu4") && !me->query_temp("wei/renwu4_1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("��������ѯС���ӵ�����","xiaobao",me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				me->set_temp("wei/renwu4_1",1);//���������ѯС���ӵ�����
				set_temp("wei/renwu4_1",1);
				say("������С�������мӣ��������������ڰ�ҵ���ˣ������ܲ��˶�ȥ����",me);
			}
			SendMenu(me);
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok"))
	{
		if(me->query_temp("wei/renwu4_7") && !me->query_temp("wei/renwu4_8") )
		{
			me->set_temp("wei/renwu4_8",1);//�����Ӧ�ؼ�
			tell_object(me,"\n����п���ǧ��������鰲˳�������أ�δ���������Ǹ�����������С�ˣ���");
			tell_object(me,"����̾�˿������������£����ǷǷǣ���������Ļ����䣡�������������С�����ȥ�ɣ���\n");

			tell_object(me,"$HIC���鿪ʼ�������ж���\n");
			
			CChar * wei = load_npc("shenlong_su");
			wei->move(environment());
			wei->set("owner",me->id(1));
			wei->set_leader(me);
			destruct(this);
		}
	}
}
NPC_END;