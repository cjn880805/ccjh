//heimuya_zhang2.h 张乘云
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_zhang2);

virtual void create()
{
	set_name("张剩云", "zhang chengyun");
	set("nickname", "白猿神魔");
	set("title", "日月神教长老");
	set("gender", "男性");
	set("age", 42);
	set("shen_type", -1);
	set("long", "他是日月神教长老。");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);

	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 300);

	set("combat_exp", 1500000);
	set("shen_type", -1);

	set_skill("force", 150);
	set_skill("kuihua_xinfa", 150);
	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("dodge", 150);
	set_skill("lingxu_bu", 150);
	set_skill("parry", 150);
	set_skill("club", 150);
	set_skill("weituo_gun", 150);

	map_skill("force", "kuihua_xinfa");
	map_skill("club", "weituo_gun");
	map_skill("parry", "weituo_gun");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu_bu");

	create_family("日月神教", 2, "长老");

	carry_object("shutonggun")->wield();
	carry_object("cloth")->wear();
}

NPC_END;