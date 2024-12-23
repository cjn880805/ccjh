// lj_miaorenhuang.h 苗人凰
// dieer 2002-7-31

NPC_BEGIN(CNlj_miaorenhuang);

virtual void create()
{
	set_name("苗人凰", "miao renhuang");
	set("title", "金面佛");
	set("long", "他看起来又高又瘦，眼神中还带着无限的失落与自责之情，似乎已全无了当年打遍天下无敌手冲天豪气。");
	set("gender", "男性");
	set("age", 42);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",16);				//设置人物形象
	set("per",25);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);
	
	set("combat_exp", 5000000);
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
