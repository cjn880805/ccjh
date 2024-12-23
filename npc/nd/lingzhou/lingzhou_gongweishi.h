// gongweishi.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_gongweishi);

virtual void create()
{
	set_name("皇宫卫士", "wei shi");
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("icon",guarder);
	set("long", "这是皇宫的大内卫士，身披钢甲，手执长剑。");
	set("combat_exp", 90000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);
	
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	carry_object("tiejia")->wear();
	carry_object("changjian")->wield();
}

NPC_END;