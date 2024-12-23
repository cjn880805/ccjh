//shanyong.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_shanyong);

virtual void create()
{
	   set_name("����", "shan yong");
	   set("long","һ�����ֵ�����ɮ�ˣ����Ц�ݣ�ȴ����Ц��ص����¡�");
	   set("title","Ѫ���ŵ��������");
	   set("gender", "����");
	   set("age", 35);
	   set("icon",young_man4);
	   set("foolid",164);        
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 2400);
	   set("mp", 800);
	   set("max_mp", 800);
	   set("mp_force", 50);
	   set("combat_exp", 200000);
	   set("score", 20000);
	   
	   set_skill("mizong_xinfa", 50);
	   set_skill("literate", 60);
	   set_skill("force", 60);
	   set_skill("parry", 60);
	   set_skill("blade", 60);
	   set_skill("dodge", 60);
	   set_skill("longxiang", 60);
	   set_skill("shenkong_xing", 60);
	   set_skill("hand", 60);
	   set_skill("dashou_yin", 60);
	   set_skill("xue_dao", 30);
	   
	   map_skill("force", "longxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("hand", "dashou_yin");
	   map_skill("parry", "xue_dao");
	   map_skill("blade", "xue_dao");
	   
	   create_family("ѩɽ��", 5, "����");
	   set("class", "bonze");
	   
	   carry_object("y_jiasha")->wear();
	   carry_object("gangdao")->wield();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (DIFFERSTR(player->querystr("gender"), "����"))
	{
		say(" Ů���������ɵģ����������̵ġ���",player);
		SendMenu(player);
		return;
	}
	
	g_Channel.do_emote(this,player, "haha", 0);
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	
	player->set("title","Ѫ���ŵ���������");
	player->UpdateMe();
}

NPC_END;