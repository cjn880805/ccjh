// xingxiu_gushou.c 鼓手

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_gushou);

virtual void create()
{
	set_name("星宿派鼓手", "gushou" );
	set("long", "他是星宿派的吹鼓手。 他面前放着一只铜鼓，一边敲一边扯着嗓子唱些肉麻的话。 ");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 20);
	set("dex", 20);
        set("icon",old_man1);
	
	set("max_hp", 1200);
	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 10);
	set("combat_exp", 4000);
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	
	set("chat_chance", 2);
	
//	carry_object("tonggu")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "鼓手敲着铜钹，高声唱道，“星～宿～老～仙，威～震～寰～宇”。 ";
	case 1:
		return "鼓手敲着铜钹，高声唱道，“星～宿～老～仙，德～配～天～地”。 ";
	case 2:
		return "鼓手敲着铜钹，高声唱道，“星～宿～老～仙，古～今～无～比”。 ";
	}
	return "";
}

NPC_END;