// lj_yuanchenzhi.h 袁成志
// dieer 2002-7-31

NPC_BEGIN(CNlj_yuanchenzhi);

virtual void create()
{
	set_name("袁成志", "yuan chenzhi");
	set("long", "他精壮结实，脸色黝黑，一双大眼却是炯炯有神。言语神情之中，自然流露出一股威势。");
	set("gender", "男性");
	set("age", 27);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("per",25);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);

	set("combat_exp",3000000);
	
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
