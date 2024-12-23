// wudang_yuhuan.c 程玉环 

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_yuhuan);

virtual void create()
{
	set_name("程小姐",  "cheng yuhuan");
	set("long", "她就是程知府的独生女儿，长得如花似玉，貌赛天仙。据说她曾经在武当门下学过剑法。 ");
	
	set("title", "知府千金");
	set("nickname", "风之花");
	set("gender", "女性");
	set("age", 18);
        set("icon",girl2);

	set("shen_type", 1);
	
	set("mp", 400);
	set("max_mp", 400);
	set("max_hp", 1200);
	set("mp_factor", 10);
	
	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji_jian", 40);
	map_skill("sword", "taiji_jian");
	map_skill("parry", "taiji_jian");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 50000);
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("pink_cloth")->wear();
	carry_object("flower_shoe")->wear();
}
NPC_END;