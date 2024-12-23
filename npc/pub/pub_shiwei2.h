// pub_shiwei2.c 带刀侍卫
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_shiwei2);

virtual void create()
{
	set_name("侍卫", "shi wei2" );

	set("icon", general);
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "aggressive");
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("blade", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
 	carry_object("gangdao")->wield();
	add_money(random(12)*100);
}

virtual void init(CChar *me)
{
	CNpc::init(me);

	if(is_fighting())	return;

	if (userp(me) && me->query_condition("killer")) 
	{
		kill_ob(me);
	}

	if( userp(me) && !is_fighting() )
	{
        switch(random(10))
		{   
        case 1:
			message_vision("侍卫忽然对$N大喝一声：何方刁民，竟敢在此撒野！看刀！",me);
			kill_ob(me);
			break;
		}
	}
}

NPC_END;