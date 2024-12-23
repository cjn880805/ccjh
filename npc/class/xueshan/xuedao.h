//xuedao.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_xuedao);

virtual void create()
{
	   set_name("Ѫ����", "xuedao wang");
	   set("long","���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�");
	   set("title","Ѫ���ŵ��Ĵ�����");
	   set("gender", "����");
	   set("age", 85);
	   set("icon",old_man1);
	   set("foolid",162);     
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 9000);
	   set("mp", 2000);
	   set("max_mp", 2000);
	   set("mp_force", 50);
	   set("combat_exp", 1800000);
	   set("score", 180000);
	   
	   set_skill("mizong_xinfa", 250);
	   set_skill("literate", 180);
	   set_skill("force", 280);
	   set_skill("parry", 280);
	   set_skill("blade", 400);
	   set_skill("sword", 220);
	   set_skill("dodge", 280);
	   set_skill("longxiang", 280);
	   set_skill("shenkong_xing", 280);
	   set_skill("hand", 280);
	   set_skill("dashou_yin", 280);
	   set_skill("mingwang_jian", 220);
	   set_skill("xue_dao", 300);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   map_skill("sword", "mingwang_jian");
	   set("chat_chance_combat", 20);  
	   
	   create_family("ѩɽ��", 4, "����");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("xblade")->wield();
	   
	   add_money(2000);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "����"))
	{
		say(" Ů���������ɵģ����������̵ġ�",player);
		SendMenu(player);
		return;
	}
	if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))
	{
		say("��ȷǱ��ŵ��ӣ�������ذɣ�",player);
		SendMenu(player);
		return;
	}
	if ((player->query("repute") )> -100000)
	{
		say(" ���ǲ����������������ɱ�˶����ᣡ",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("longxiang", 1) < 60)
	{
		say("����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "haha", 0);
	g_Channel.do_emote(this,player, "nod", 0);
	
	command(snprintf(msg, 40,"recruit %ld",player->object_id()) );
	
	player->set("title","Ѫ���ŵ��������");
	player->UpdateMe();
}

NPC_END;