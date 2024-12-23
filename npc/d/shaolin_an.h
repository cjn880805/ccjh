// shaolin_an.c 安健刚
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_an);

virtual void create()
{
	set_name("安无恙", "an jiangang");
	set("nickname",  "剑齿虎" );
	set("long", "他是铁剑凌丘雄的二弟子，对师父始终忠心不二。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man6);
	
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("throwing", 50);
	set_skill("mantian_xing", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("jingang_quan", 50);
	
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("throwing", "mantian_xing");
	map_skill("unarmed", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	set("env/wimpy", 20);
	create_family("少林派", 52, "俗家弟子");
	
	carry_object("cloth")->wear();
	carry_object("tiedan")->wield();
}
NPC_END;
