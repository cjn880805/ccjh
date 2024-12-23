//xiaoguiz.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaoguizi);

virtual void create()
{
	set_name("小桂子","xiaoguiz");

	set("icon", young_man3);
	set("gender", "无性" );
	set("age", 13);
	set("long","这位小太监在一旁小心侍侯着，手里拿着一包药。");
	set("combat_exp", 1000);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);

	set("attitude", "friendly");
	set("rank_info/respect", "小公公");
    set("chat_chance", 5);


    carry_object("cloth")->wear();
	carry_object("yaofen");
	add_money(10);


};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "小桂子说道：公公，再服一剂药，好不好？";
	case 1:
		return "小桂子说道：再服半剂，多半不打紧。";
	}
	return "";
}

NPC_END;
