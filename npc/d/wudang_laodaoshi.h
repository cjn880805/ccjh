// wudang_laodaoshi.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_laodaoshi);

virtual void create()
{
	set_name("老道士", "lao daoshi");
	set("long", "这是一个精壮老道士。 ");
	
	set("gender", "男性");
	set("attitude", "peace");
	set("class", "taoist");
	
	set("age", 67);
        set("icon",taoist);

	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("tiyunzong", 50);
	set_skill("taiji_shengong", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "tiyunzong");
	
	carry_object("greyrobe")->wear();
	add_money( 500);
}

NPC_END;