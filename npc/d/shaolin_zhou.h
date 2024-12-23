// shaolin_zhou.c 周仲英

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_zhou);

virtual void create()
{
	set_name("凌丘雄",  "zhou zhongying");
	set("title",  "铁剑庄庄主" );
	set("nickname",  "铁剑" );
	set("long", "他白发飘动，精神矍铄，乃是西北武林的领袖人物之一的铁剑凌丘雄。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 61);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("max_hp", 9000);
	set("hp",  3000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 500000);
	
	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("unarmed", 140);
	set_skill("parry", 140);
	set_skill("throwing", 140);
	set_skill("mantian_xing", 140);
	set_skill("hunyuan_yiqi", 140);
	set_skill("jingang_quan", 140);
	set_skill("shaolin_shenfa", 140);
	
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("throwing", "mantian_xing");
	map_skill("parry", "jingang_quan");
	map_skill("unarmed", "jingang_quan");
	
	set("env/wimpy", 20);
	create_family("少林派", 51, "俗家弟子");
	
	carry_object("cloth")->wear();
	carry_object("tiedan")->wield();
}

NPC_END;