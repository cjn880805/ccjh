NPC_BEGIN(CNpub_huyuan);
//inherit F_CLEAN_UP;

virtual void create()
{
	set_name("护院","huyuan");
	
	set("icon", triggerman2);
	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 10050);
	set("mp", 1350);
	set("max_mp", 1350);
	set("mp_factor", 100);
	set("combat_exp", 300000);
	set("score", 100);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);
	
	create_family("梅庄", 3, "弟子");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	
};


NPC_END;
