// zu.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_zu);

virtual void create()
{
	set_name("祖万代", "zu qianqiu");
	set("nickname", "黄河老祖");
	set("gender", "男性" );
	set("age", 52);
	set("long", 
		"一个衣衫褴偻的落魄书生。焦黄脸皮，一个酒糟鼻，疏疏落落的\n"
		"几根胡子，两眼无神。衣衫上一片油光，右手拿了一把破折扇。\n");
	
	set("combat_exp", 100000);
	set("attitude", "friendly");
	
	set("hp",500);
	set("max_hp",500);
	set("per", 17);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon",old_man2);
	
	set_skill("literate", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	
//	add_money("gold", 1);
	carry_object("cloth")->wear();
}

NPC_END;