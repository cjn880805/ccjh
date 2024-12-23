//trade.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_trade);

virtual void create()
{
	set_name("波斯商人","trade");
	
	set("icon", pub_boss);
	set("gender", "男性");
	set("age", 40 + random(10));
	
	set("long", "一个高鼻蓝眼的波斯商人。他看着你脸上露出狡猾的笑容。");
	
	set("attitude", "friendly");
	set("combat_exp", 6000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
	
	set("chat_chance", 1);
	
	carry_object("wandao")->wield();
	carry_object("changpao")->wear();
	add_money(20);
	
};

virtual char * chat_msg(CChar *me )
{
	switch(random(2))
	{
	case 0:
		return "波斯商人对你挤了一下眼睛";
	case 1:
		return "波斯商人说道：阿拉阿可巴，穆罕默德瑞素阿拉。 你没听懂。";
	}
	return "";
}
NPC_END;
