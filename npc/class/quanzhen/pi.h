// pi.c 皮清玄
//Lanwood
//2001-01-15

NPCQUANZHEN_BEGIN(CNquanzhen_pi);

virtual void create()
{
	set_name("皮静玄", "pi jingxuan");
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long", "他是一位体格强健的壮年道士，似乎身怀武艺。");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("foolid",56);
	set("chat_chance_combat", 60);
	set("hp", 500);
	set("max_hp", 1500);
	
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	set("combat_exp", 160000);
	set("score", 100000);
	
	set_skill("force", 40);
	set_skill("xiantian_qigong", 40);    //先天气功
	set_skill("sword", 40);
	set_skill("quanzhen_jian",40);  //全真剑
	set_skill("dodge", 40);
	set_skill("jinyan_gong", 40);   //金雁功
	set_skill("parry", 40);
	set_skill("strike",40);
	set_skill("unarmed",40);
	set_skill("haotian_zhang", 40);    //昊天掌
	set_skill("literate",40);
	set_skill("taoism",40);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 4, "弟子");
	
	set_inquiry("全真教", "我全真教是天下道家玄门正宗。");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
}

NPCQUANZHEN_END;