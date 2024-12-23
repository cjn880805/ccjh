// shaolin_zhouyi.c 周绮

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_zhouyi);

virtual void create()
{
	set_name("凌锦", "zhou yi");
	set("title",  "铁剑庄大小姐" );
	set("nickname",  "俏张飞" );
	set("long","这是铁剑庄的大小姐，凌丘雄的宝贝女儿。她性格豪迈，颇有乃父之风，爱管闲事，好打不平，西北武林中人送了她个外号，叫做“俏张飞”。");
	set("gender", "女性");
	set("class", "fighter");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",girl1);
	
	set("max_hp", 2400);
	set("hp",  800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 60);
	set("combat_exp", 40000);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("jingang_quan", 50);
	
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "cibei_dao");
	map_skill("unarmed", "jingang_quan");
	map_skill("parry", "cibei_dao");
	
	set("env/wimpy", 20);
	create_family("少林派", 51, "俗家弟子");
	
	carry_object("jinduan")->wear();
	carry_object("gangdao")->wield();
}

NPC_END;