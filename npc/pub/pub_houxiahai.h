NPC_BEGIN(CNpub_houxiahai);

virtual void create()
{
	set_name("侯下海","houxiahai");

	set("icon", young_man6);
	set("gender", "男性");
	set("nickname", "九纹龙");
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 11);
	set("long", "侯下海是个青脸瘦子，面颊极长，脸上还纹了九条龙，非常难看。");
	set("combat_exp", 100000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("club", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("fork")->wield();
	carry_object("cloth")->wear();
};



NPC_END;
