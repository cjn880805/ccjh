// old.c
//code by sound
//2001-07-12

NPC_BEGIN(CNshenlong_old);

virtual void create()
{
	set_name("老者", "old man");
	set("title", "神龙教老者");
 	set("icon",old_man2);
	set("long",
		"这是一个神龙教老者，太阳穴高耸，两眼炯炯有神，显然武功甚高。然而神色郁郁，对一帮年轻男女颇为有礼，似乎害怕什么，样子十分可怜。");
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 30+random(50));
	set("shen_type", -1);
	set("str", 35+random(10));
	set("dex", 35+random(10));
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 25+random(25));
	set("combat_exp", 100000+random(100000));
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	
	carry_object("xionghuang")->wield();
	carry_object("cloth")->wear();
}

NPC_END;