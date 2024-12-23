// sha.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_sha);

virtual void create()
{
	set_name("沙遁地",  "sha tongtian");
	set("gender", "男性");
	set("title", "黄河帮帮主");
	set("nickname", "鬼门龙王");
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 12);
	set("icon",cateran);
	
	set("long", 
		"沙通天是个秃子，头上油光光地没半根头发，双目布满红丝，眼\n"
		"珠突出，生就一副异相。性子暴躁，武功却是出奇地高，江湖上\n"
		"无人不晓。\n");
	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("club", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	
	set("mp", 800); 
	set("max_mp", 800);
	set("mp_factor", 50);
	
	carry_object("tiejiang")->wield();
	carry_object("tiejia")->wear();
}

NPC_END;