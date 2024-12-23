// pub_herdsman.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_herdsman);


virtual void create()
{
	set_name("牧羊人","herds man");

	set("icon", old_man2);
	set("gender", "男性");
	set("age", 60 + random(10));
	set("long", "一个维吾尔族老汉，赶着几十只羊。");
	set("attitude", "friendly");
	set("combat_exp", 1000);
	set("shen_type", 1);
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("whip", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set_inquiry ("星宿派" , "他们躲在星宿海。");
	set_inquiry ("星宿海" , "星宿海在深涧西边。");


	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
	carry_object("changbian")->wield();
}

virtual char * chat_msg()
{
	switch (random(2) )
	{
	case 0:
		return "牧羊老汉伤心地说道：那帮星宿派弟子昨天又抢了我一只羊。";
	case 1:
		return "牧羊老汉呆呆的望着羊群发起愣来了。";
	}
	return "";
}

NPC_END;