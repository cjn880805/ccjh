// xingxiu_haoshou.c 号手

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_haoshou);

virtual void create()
{
	set_name("星宿派号手", "haoshou" );
	set("long", "他是星宿派的吹鼓手。 他手中拿着一只铜号，鼓足力气沉醉地吹着。 ");
	set("gender", "男性");
	set("age", 33);
        set("icon",young_man2);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	set("combat_exp", 3000);
	
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	
//	carry_object("tonghao")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "星宿派号手说道：“星～宿～老～仙，威～震～寰～宇”。 ";
	case 1:
		return "星宿派号手说道：“星～宿～老～仙，德～配～天～地”。 ";
	case 2:
		return "星宿派号手说道：“星～宿～老～仙，古～今～无～比”。 ";
	}
	return "";
}

NPC_END;