//peng.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_peng);

virtual void create()
{
	set_name("彭有劲", "peng youjing");
	set("title", "丐帮九袋长老");
	set("nickname", "掌钵龙头");
	set("gender", "男性");
	set("age", 50);
	set("long", 
		"庞有劲是丐帮中净衣派的首领，衣着干净华丽，不象叫化子。");
	set("icon",begger);

		
	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("hp", 900);
	set("max_hp", 2700);
	
	set("mp", 1300);
	set("max_mp", 1200);
	set("mp_factor", 100);
	
	set("combat_exp", 220000);
	set("score", 20000);
	
	set_skill("force", 90);				// 基本内功
	set_skill("huntian_qigong", 90);	// 混天气功
	set_skill("unarmed", 85);			// 基本拳脚
	set_skill("xianglong_zhang", 80);	// 降龙十八掌
	set_skill("dodge", 105);			// 基本躲闪
	set_skill("xiaoyaoyou", 95);		// 逍遥游
	set_skill("parry", 90);				// 基本招架
	set_skill("staff", 90);				// 基本棍杖
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 20);
	carry_object("gao4");
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	say("老夫不收徒弟，还是请回吧。");
}

NPC_END;
