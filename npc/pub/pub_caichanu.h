NPC_BEGIN(CNPub_caichanu);

virtual void create()
{
	set_name("采茶女","caichanu");

	set("icon", young_woman5);
	set("gender", "女性" );
	set("age", 19);
	set("per", 40);
	set("long", "江南清秀的采茶姑娘一样楚楚动人。");
	set("combat_exp", 700);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
	set_skill("parry", 25);
	set_skill("dodge", 30);
	
	set("chat_chance", 5);
	
	add_money(15);
	carry_object("cloth")->wear();
	
};

virtual char * chat_msg(CChar * me)
{
	return "采茶女说道：侬今早去庙里上香伐，带我一道去好勿好？";
}

NPC_END;
