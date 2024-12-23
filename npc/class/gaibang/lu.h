//lu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_lu);

virtual void create()
{
	set_name("鲁有腿", "lu youjiao");
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"关进虽然武功算不得顶尖高手，可是在江湖上却颇有声望。");
		
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 9);

	set("hp", 900);
	set("max_hp", 2700);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	set("score", 40000);
	
	set_skill("force", 150);		// 基本内功
	set_skill("huntian_qigong", 150);	// 混天气功
	set_skill("unarmed", 170);		// 基本拳脚
	set_skill("xianglong_zhang", 180);	// 降龙十八掌
	set_skill("dodge", 90);			// 基本躲闪
	set_skill("xiaoyaoyou", 90);		// 逍遥游
	set_skill("parry", 120);		// 基本招架
	set_skill("staff", 160);		// 基本棍杖
	set_skill("dagou_bang", 160); 
	set_skill("begging", 100);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 20);
	set("no_huan",1);
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
	if ( me->query_int() >= 25 ) 
	{
		say("我们丐帮的武艺一向以刚猛为主，你聪慧过人，似乎不宜学丐帮的功夫？", me);
		SendMenu(me);
		return;
	}
	else
		accept_student(me);
}

NPC_END;
