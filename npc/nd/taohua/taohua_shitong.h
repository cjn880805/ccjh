// shitong.c 侍童
//sound 2001-07-18

NPC_BEGIN(CNtaohua_shitong);

virtual void create()
{
	set_name("侍童", "shi tong");
	set("age", 8);
	set("gender", "男性");
	set("long", "这是一个桃花岛试剑亭的侍童。");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_skill("force", 60);
	set("icon",boy1);			//设置人物形象

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);
	
	carry_object("cloth")->wear();
}

NPC_END;