//wudunlu.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_wudunlu);

virtual void create()
{
	set_name("大武","wu dun lu");

	set("title", "靖哥哥大弟子");
	set("gender", "男性");
	set("age", 23);
	set("long", "他是靖哥哥的大弟子，相貌英俊，但一副落魄潦倒的样子。");
 	set("attitude", "peaceful");
 	set("icon",young_man2);
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set_inquiry("蓉儿","那是我师母。");
	set_inquiry("靖哥哥","那是我师父。");

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);
	 
	set_skill("force", 50);			// 基本内功
	set_skill("huntian_qigong", 50);	// 混天气功
	set_skill("unarmed", 50);		// 基本拳脚
	set_skill("xianglong_zhang", 50);	// 降龙十八掌
	set_skill("dodge", 50);			// 基本躲闪
	set_skill("xiaoyaoyou", 50);		// 逍遥游
	set_skill("parry", 50);			// 基本招架
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

NPC_END;

