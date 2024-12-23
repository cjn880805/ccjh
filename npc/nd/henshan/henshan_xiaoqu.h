// xiaoqu.c 曲非烟
//code by sound
//2001-07-16

NPC_BEGIN(CNhenshan_xiaoqu);

virtual void create()
{
	set_name("曲轻烟", "qu feiyan");
	set("gender", "女性" );
	set("age", 12);
	set("long", "她是曲长老的宝贝孙女儿，有十二、三岁了吧。");
//	set_temp("apply/defense", 5);
	set("combat_exp", 70);
//	set("shen", 100);
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("icon",girl2);
	
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
}

NPC_END;