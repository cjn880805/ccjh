// xingxiu_boshou.c 钹手

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_boshou);

virtual void create()
{
	set_name("星宿派钹手",  "boshou");
	set("long","他是星宿派的吹鼓手。他手中拿着一对铜钹，一边敲一边扯着嗓子唱些肉麻的话。 ");
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
        set("icon",young_man6);
	
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 10);
	set("combat_exp", 2000);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	
	set("chat_chance", 2);
	
//	carry_object("tongbo")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "星宿派钹手唱道：“星～宿～老～仙，威～震～寰～宇”。 ";
	case 1:
		return "星宿派钹手唱道：“星～宿～老～仙，德～配～天～地”。 ";
	case 2:
		return "星宿派钹手唱道：“星～宿～老～仙，古～今～无～比”。 ";
	}
	return "";
}

NPC_END;
