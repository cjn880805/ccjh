//baoxiang.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_baoxiang);

virtual void create()
{
	   set_name("����", "bao xiang");
	   set("long","һ�����߼��ݵ�ɮ�ˣ�������â���䡣������Ѫ���������£������ĺ�������");
	   set("title","Ѫ���ŵ��������");
	   set("gender", "����");
	   set("age", 35);
	   set("icon",young_man5);
	   
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 3000);
	   set("mp", 1000);
	   set("max_mp", 1000);
	   set("mp_force", 50);
	   set("combat_exp", 250000);
	   set("score", 35000);
	   
	   set_skill("mizong_xinfa", 60);
	   set_skill("literate", 120);
	   set_skill("force", 120);
	   set_skill("parry", 120);
	   set_skill("blade", 120);
	   set_skill("dodge", 120);
	   set_skill("longxiang", 120);
	   set_skill("shenkong_xing", 120);
	   set_skill("hand", 120);
	   set_skill("dashou_yin", 120);
	   set_skill("xue_dao", 120);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   
	   create_family("ѩɽ��", 5, "����");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("gangdao")->wield();
	   
	   add_money(1000);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "����"))
	{
		say("Ů���������ɵģ����������̵ġ���",player);
		SendMenu(player);
		return;
	}
	
	if (player->query("repute")>0)
	{
		say(" ������������������Ļ�����");
		kill_ob(player);
		return;
	}
	
	if (player->query_skill("longxiang", 1) < 60) 
	{
		say(" ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "nod", 0);
	
	command(snprintf(msg,40,"recruit %ld",player->object_id()) );
	
	player->set("title", "Ѫ���ŵ���������");
	player->UpdateMe();
}


NPC_END;