// pub_huangzhen.c
// code by Fisho
// date:2000-12-17
//inherit F_BANKER;

BANKOWNER_BEGIN(CNpub_huangzhen);

virtual void create()
{
	set_name("钟丹","zhong dan");

	set("icon", young_woman7);
	set("nickname", "铜笔铁算盘");
	set("gender", "女性");
	
	set("age", 59);
	set("long","钟丹是神剑仙猿穆桂英的开门大弟子，也是这个钱庄的老板，管理襄阳军饷。");
	set("attitude", "peaceful");
	set("per", 21);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 30);
	
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	
	set("combat_exp", 300000);
	set("shen_type", 1);
	
	set("chat_chance_combat", 80);
	
	set_skill("strike", 80);
	set_skill("cuff", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("literate", 100);
	
	set_skill("huashan_sword", 80);
	set_skill("zixia_shengong", 80);
	set_skill("poyu_quan", 80);
	set_skill("hunyuan_zhang", 80);
	set_skill("feiyan_huixiang", 80);
	
	map_skill("sword", "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("force", "zixia_shengong");
	map_skill("cuff", "poyu_quan");
	map_skill("strike", "huntian_zhang");
	map_skill("dodge", "feiyan_huixiang");
	prepare_skill("cuff", "poyu_quan");
	prepare_skill("strike", "huntian_zhang");
	
	create_family("华山派", 21, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
	
}
/*

virtual void init(CChar *me)
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
			(: exert_function, "recover" :)
	}) );
*/

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

BANKOWNER_END;