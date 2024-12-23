// shaolin_seng.c
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_seng);

virtual void create()
{
	set_name("老和尚", "lao heshang");
	set("long",	"一个慈眉善目的老和尚。");
	
	set("gender", "男性");
	set("attitude", "peace");
	set("class", "bonze");
        set("icon",old_man2);
	
	set("age", 67);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cibei_dao", 50);
	set_skill("hunyuan_yiqi", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");
	
	carry_object("cloth")->wear();
	add_money( 5000);
}

NPC_END;