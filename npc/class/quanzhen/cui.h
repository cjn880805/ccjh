// quanzhen_cui.c 崔志方

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_cui);

virtual void create()
{
	set_name("崔志圆", "cui zhiyuan");
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long","他就是全真教第三代弟子中的好手，王老五的二弟子。");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("icon",taoist);
	set("foolid",53);
	set("chat_chance_combat", 60);
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	
	set("combat_exp", 160000);
	set("score", 100000);
	
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 100);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("strike",80);

	set_skill("xiantian_qigong", 120);    //先天气功
	set_skill("quanzhen_jian",120);  //全真剑
	set_skill("jinyan_gong", 100);   //金雁功
	set_skill("haotian_zhang", 120);    //昊天掌

	set_skill("literate",100);
	set_skill("taoism",80);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 3, "弟子");
	
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
 	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];

	if ( ob->query_skill("xiantian_qigong",1) < 35 )
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<3000)
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。", ob);
		SendMenu(ob);
		return;
	}
	
	say(" 好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPCQUANZHEN_END;