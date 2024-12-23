// pub_fengliang.c
//code by Fisho
//date : 2000-12-14

//inherit F_UNIQUE;

NPC_BEGIN(CNpub_fengliang);

virtual void create()
{
	set_name("风凉","feng liang");

	set("icon", young_man6);
	set("title",  "青龙门掌门人" );
	set("long", "他是个高大的中年汉子，腰里缠九节鞭。");
	set("gender", "男性");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("whip", 50);
	set_skill("riyue_bian", 50);
	set_skill("lingxu_bu",50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "riyue_bian");
	map_skill("whip", "riyue_bian");
	
	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	
	carry_object("jiujiebian")->wield();
	carry_object("tiebeixin")->wear();
}

NPC_END;