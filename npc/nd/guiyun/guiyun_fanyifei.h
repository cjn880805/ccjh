// fanyifei.h
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_fanyifei);

virtual void create()
{
	set_name("范双翔", "fan yifei");
	set("title", "鹤笔门掌门人");
	set("long", "他是一个矮瘦的老者，一张黑脸。腰里插着判官笔，人称‘辽东鹤’。");
	set("gender", "男性");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon", old_man2);

	set("hp", 1000);	
	set("max_hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("dagger", 50);
	set_skill("shigu_bifa", 50);
	set_skill("lingxu_bu",50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "shigu_bifa");
	map_skill("dagger", "shigu_bifa");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	
	carry_object("panguanbi")->wield();
	carry_object("cloth")->wear();
}

NPC_END;