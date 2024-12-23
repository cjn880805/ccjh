// shagu.c
//sound 2001-07-18

NPC_BEGIN(CNtaohua_shagu);

virtual void create()
{
	set_name("傻女", "shagu");
	set("gender", "女性");
	set("age", 41);
//	set_race("human");
	set("class","taohua");
	
	set("long","傻女是个傻乎乎的中年妇人，可打扮装束却还象个小姑娘。");
//	set("rank_info", "桃花岛弟子");
	
	set("max_gin", 800);
	set("max_kee", 800);
	set("max_sen", 800);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("max_mp", 1000);
	set("mp", 1000);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("icon",young_woman11);			//设置人物形象
	
	set("combat_exp", 100000);
	set("score",50000);
	
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("finger", 80);
	set_skill("sword", 80);
	
	set_skill("bibo_shengong",65);
	set_skill("luoying_shenjian",62);
	set_skill("luoying_shenzhang",62);
//	set_skill("bagua_steps",62);
	set_skill("anying_fuxiang",62);
	set_skill("lanhua_shou",62);
	
	map_skill("dodge",  "anying_fuxiang");
	map_skill("unarmed","lanhua_shou");
	map_skill("parry",  "luoying_shenjian");
	map_skill("force",  "bibo_shengong");
	map_skill("sword",  "luoying_shenjian");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}
/*
int accept_fight(object who)
{
	object ob;
	
	ob=this_object();
	
	ob->set("gin", 800);
	ob->set("kee", 800);
	ob->set("eff_kee", 800);
	ob->set("sen", 800);
	
	ob->set("atman", 1000);
	ob->set("force", 1000);
	ob->set("mana", 1000);
	
	command("say 打架啊，打架啊，真有趣。\n");
	return 1;
}

int accept_kill(object who)
{
//	do_chat("\n");
}

void lose_fight(object me)
{
	me->set_temp("win_shagu",1);
	write("lose!\n");
}
*/
NPC_END;