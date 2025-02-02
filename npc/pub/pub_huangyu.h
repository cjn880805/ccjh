//huangyu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_huangyu);

virtual void create()
{
	set_name("黄宇","huangyu");

	set("icon", pawnshop_boss);
	set("title", "当铺老板");
	set("nickname", "老滑头");
	

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 55);
	set("str", 100);
	set("long", "一个老奸商，你要被宰了！");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();

};

void die()
{
	message_vision("$N死了。", this);
	destruct(this);
}

NPC_END;
