// meizhuang_ding.c
//code by Fisho
//date:2000-12-21
//inherit F_CLEAN_UP;

NPC_BEGIN(CNmeizhuang_ding);

virtual void create()
{
	set_name("丁柔", "ding jian");
	set("long","他就是隐居江湖数年的环形电剑丁柔，现在在梅庄当管家。");
	set("gender", "男性");
	set("nickname", "环形电剑");
	set("attitude", "friendly");
 	set("icon",old_man2);
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 3350);
	set("hp",  3350);
	set("mp", 1350);
	set("max_mp", 1350);
	set("mp_factor", 1);
	set("combat_exp", 100000);
	set("score", 100);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);
	
	create_family("梅庄", 2, "弟子");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();

}

NPC_END;