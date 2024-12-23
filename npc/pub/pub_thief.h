NPC_BEGIN(CNPub_thief);
//inherit F_DEALER;
virtual void create()
{
	set_name("小偷","thief");

	set("icon", young_man4);
	

	set("no_beg_from", 1);

	set("gender", "男性");
	set("age", 35);
	set("long", "一个技术熟练的小偷");

	set_temp("apply/attack", 1);
	set_temp("apply/attack", 1);
	set_temp("apply/damage", 1);

	set("combat_exp", 51);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
    add_money(5000);
};

NPC_END;
