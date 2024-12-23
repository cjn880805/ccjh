//guoshi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_guoshi);

virtual void create()
{
	   set_name("���Ʋֹ�ʦ", "gongtangcang guoshi");
	   set("long","���Ʋֹ�ʦ��ѩɽ���е�λ�ϸߵ������һ����ɫ���ģ�ͷ��ɮñ��");
	   set("title", "������" );
	   set("nickname", "��ʦ" );
	   set("gender", "����");
	   set("age", 40);
	   set("foolid",159);
	   set("icon",young_man6);
	   
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 24);
	   set("int", 28);
	   set("con", 26);
	   set("dex", 25);
	   
	   set("max_hp", 4500);
	   set("mp", 1500);
	   set("max_mp", 1500);
	   set("mp_force", 20);
	   set("combat_exp", 500000);
	   set("score", 80000);
	   
	   set_skill("mizong_xinfa", 60);
	   set_skill("literate", 50);
	   set_skill("force", 100);
	   set_skill("xiaowuxiang", 100);
	   set_skill("dodge", 100);
	   set_skill("shenkong_xing", 80);
	   set_skill("parry", 70);
	   set_skill("staff", 80);
	   set_skill("xiangmo_chu", 80 );
	   set_skill("hammer",50);
	   set_skill("riyue_lun",40);
	   set_skill("unarmed", 90);
	   set_skill("yujiamu_quan", 80);
	   
	   
	   map_skill("force", "xiaowuxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("unarmed", "yujiamu_quan");
	   map_skill("parry", "xiangmo_chu");
	   map_skill("staff", "xiangmo_chu");
	   map_skill("hammer", "riyue_lun");
	   
	   create_family("ѩɽ��", 4, "������");
	   set("class", "bonze");
	   
	   set_inquiry("���",ask_for_join);
	   //set_inquiry("���ֳ�ת",do_say);
	   
	   carry_object("chanzhang")->wield();
	   carry_object("c_jiasha")->wear();
	   carry_object("sengmao")->wear();
	   
	   add_money(1000);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "����"))
	{
		say("��ϰ�����ڹ���Ҫ����֮�塣",player);
		say("��λʩ��������ذɣ�",player);
		SendMenu(player);
		return;
	}
	
	if (DIFFERSTR(player->querystr("class"), "bonze"))
	{
		say(" �ҷ��ŵ����������ࡣ",player);
		player->set_temp("pending/join_bonze", 1);
		say("ʩ������������ҷ𣬾�������ܽ�");
		SendMenu(player);
		return;
	}
	
	if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))   
	{
		say(" ��λʩ���ȷǱ��µ��ӣ�������ذɣ�",player);
		say(" ��λʩ�������ȸ����ײ�ʦ��ѧϰ��",player);
		SendMenu(player);
		return;
	}
	
	if (player->query_skill("mizong_xinfa", 1) < 40) 
	{
		say(" ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�",player);
		say(" �㻹Ӧ�ö�����б��ŵ��ķ�",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "smile", 0);
	g_Channel.do_emote(this,player, "nod", 0);
	
	say(" �ʹ���һЩ�书�ɣ�",player);
	SendMenu(player);
	command(snprintf(msg,40,"recruit %ld",player->object_id()) );
	
	player->set("title", "����");
	player->UpdateMe();
}

static char * ask_for_join(CNpc * npc , CChar * player)
{
	if(EQUALSTR(player->querystr("class"), "bonze") )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��";
	
    if(DIFFERSTR(player->querystr("gender"), "����") )
        return "ʩ��������������ǿ�ϲ�ɺأ���ϧ����ֻ����ͽ��";
	
    player->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ�������ܽ䡣";
	
	npc->AddMenuItem("�¹�", "kneel", player);
	npc->AddMenuItem("�뿪", "", player);
	npc->SendMenu(player);
	
	return "";
	
}

virtual int do_talk(CChar * player , char * ask=NULL)
{
	if(!ask) return 0;
	
	if(player->query_temp("pending/join_bonze"))
	{
		if(strcmp(ask, "kneel") == 0)
		{
			return do_kneel(player);
		}
		return 1;
	}
	return CNpc::do_talk(player, ask);
}

int do_kneel(CChar * player)
{
    if( !player->query_temp("pending/join_bonze") )
		return 0;
	
	message_vision("$N˫�ֺ�ʮ�����������ع���������$n˵�ʵ���һ΢�������������ɾ�һ��΢����������΢���಻������һ������˼ɲ������������$N��ͷ�ڷ��������£�ͷ����ͺͺ�ظ���һ��ͷ�����������굶����������ȸɾ���",player);
	
	player->delete_temp("pending/join_bonze");
	player->set("class", "bonze");
    g_Channel.do_emote(this, player, "smile", 0);
	
	return 1;
}

static char * do_say(CNpc * npc , CChar * player)
{
	player->move(load_room("ѩɽ��"));
	return "";
}
NPC_END;