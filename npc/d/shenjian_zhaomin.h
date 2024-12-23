// shenjian_zhaomin.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;

NPC_BEGIN(CNshenjian_zhaomin);

virtual void create()
{
	set_name("赵灵", "zhao min");
	set("title",  "大元绍灵公主" );
	set("long","她脸泛红霞，容色过人。十分美丽之中，更带着三分英气，三分豪态，同时雍容华贵，自有一副端严之致，令人肃然起敬，不敢逼视。 ");
    set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
 	set("icon",girl2);
	
	set("max_hp", 1500);
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	set("chat_chance_combat", 60);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("liangyi_jian", 80);
	set_skill("huifeng_jian", 80);
	set_skill("taiji_shengong", 90);
	set_skill("changquan", 80);
	set_skill("lingxu_bu", 80);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "liangyi_jian");
	map_skill("sword", "liangyi_jian");
	map_skill("unarmed", "changquan");
	set_temp("is_riding", "紫骝马");
	set("chat_chance", 30);
	/*	set("chat_msg", ({
	(: random_move :)
	}) );
	*/
	set_inquiry("张无忌","张公子远在昆仑，不知他近来可好？秋冷春寒，可有寒衣？ ");
	set_inquiry("倚天剑","倚天为天下神兵。 ");
	
	carry_object("changjian")->wield();
	carry_object("female2_cloth")->wear();
	add_money(1000);
}
/*	set("chat_msg_combat", ({
(: perform_action, "sword.ren" :),
}) );
*/	
virtual char * chat_msg_combat()
{
	perform_action("sword ren");
	return 0;
}

NPC_END;