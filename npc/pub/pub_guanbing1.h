// pub_guanbing1.c 官兵
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_guanbing1);

virtual void create()
{
	set_name("官兵", "guan bing1");

	set("icon", guarder);
	set("age", 22);
	set("gender", "男性");
	set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。");
	set("attitude", "peaceful");
	
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	
	set("chat_chance_combat", 10);

	carry_object("gangdao")->wield();
	carry_object("junfu")->wear();
	carry_object("jitui");
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "官兵说：大胆刁民，竟敢造反不成？";
	case 1:
		return "官兵说：跑得了和尚跑不了庙，你还是快快束手就擒！";
	}
	return "";
}

virtual void init(CChar *me)
{
	CNpc::init(me);

	if(userp(me) && me->query_condition("killer")) 
	{
		kill_ob(me);
	}
}

virtual int accept_fight(CChar * me)
{
	say("大爷我正想找人杀呐，今天算你倒霉。");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}

NPC_END;