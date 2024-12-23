// shoumu.c 守墓家奴
//sound 2001-07-18

NPC_BEGIN(CNtaohua_shoumu);

virtual void create()
{
	set_name("守墓家奴", "shou mu");
	set("age", 28);
	set("gender", "男性");
	set("long", "他是桃花岛岛主夫人的守墓家奴。");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("icon",boy2);			//设置人物形象
	set("shen_type", 1);
	set("combat_exp", 100000);
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 40);
	set_skill("sword", 80);
	set_skill("literate", 20);
	set_skill("jiuyin_baiguzhao", 90);
	set_skill("luoying_shenjian",90);
	set_skill("bibo_shengong", 90);
	set_skill("anying_fuxiang", 90);
	
	map_skill("force", "bibo_shengong");
	map_skill("parry", "luoying_shenjian");
	map_skill("sword", "luoying_shenjian");
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed", "jiuyin_baiguzhao");
	
	create_family("桃花岛", 3, "守墓弟子");
	
	carry_object("cloth")->wear();
}

NPC_END;