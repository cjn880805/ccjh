NPC_BEGIN(CNPub_fengzaiming);

virtual void create()
{
	set_name("凤再鸣","fengzaiming");

	set("icon", smith_boss);
	set("gender", "男性");
	set("age", 25);
	set("long", "他是佛山镇上大财主凤东南之子。只见他步履轻捷，脸上英气勃勃，显是武功不弱。");
	set("combat_exp", 40000);

	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("wuhuduanmendao", 70);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 10);

	map_skill("blade", "wuhuduanmendao");
	map_skill("parry", "wuhuduanmendao");

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 20);
	carry_object("gangdao")->wield();
	carry_object("zhaohong")->wear();
	add_money(1500);
};

NPC_END;
