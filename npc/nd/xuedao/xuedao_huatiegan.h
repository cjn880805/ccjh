// huatiegan.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_huatiegan);

virtual void create()
{
	set_name("花铜杆", "hua tiegan");
	set("long", 
		"他就是南四奇“落花流水”中的老二。南四奇横行江南，行侠仗义，一手中平枪，号称中平无敌。可是他的为人却不咋的。");
	set("gender", "男性");
	set("nickname", "中平无敌");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 0l);
	set("str", 35);
	set("int", 38);
	set("con", 35);
	set("dex", 35);
	set("icon",young_man5);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);
	set("combat_exp", 700000);
	set("shen_type", 0l);
	
	set_skill("force", 100);
	set_skill("zixia_shengong", 100);
	set_skill("dodge", 100);
	set_skill("lingxu_bu", 100);
	set_skill("unarmed", 100);
	set_skill("poyu_quan", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("zhongpingqiang", 100);
	set_skill("literate", 40);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "poyu_quan");
	map_skill("club", "zhongpingqiang");
	map_skill("parry", "zhongpingqiang");
	set("chat_chance", 20);
	
	
	carry_object("changqiang")->wield();
}

virtual char * chat_msg()
{
	return "花铜杆急提中气，啸声如虹：“落花流水～～……”声势劲急，远远传开。";
}

NPC_END;