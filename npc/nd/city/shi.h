// shi.h 史青山
//zhangdongni  2001-07-18


NPC_BEGIN(CNcity_shi);

virtual void create()
{

	set_name("史泰山", "shi taishan");
	set("title", "扬州守将");
	set("gender", "男性");
	set("cion",young_man4);
	set("age", 33);
	set("str", 27);
	set("dex", 15);
	set("int", 15);
	set("con", 27);
	set("long", "史青山曾经是武当山的俗家弟子，不知为何吃上了朝廷饭。\n");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("taiji_jian", 50);
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("hp", 3000);
	set("max_hp",3000);
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor",300);
	
//	carry_object("gangjian")->wield();
//	carry_object("tiejia")->wear();
	
	
}
/*
int accept_fight(object me)
{
	command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
	return 0;
}
*/
NPC_END;