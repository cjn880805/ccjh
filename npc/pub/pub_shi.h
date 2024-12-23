// pub_shi.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_shi);


virtual void create()
{
	set_name("施恩", "shi en" );

	set("icon", pub_boss);
	set("long",	"他就是隐居江湖数年的金眼彪施恩，现在在梅庄当管家。");
	
	set("gender", "男性");
	set("nickname", "金眼彪");
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
	set("chat_chance", 10);
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

virtual char * chat_msg()
{
	return "施恩神情慌张的朝桌子后面瞧了一眼。";
}

NPC_END;