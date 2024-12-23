// lingjiu_lanjian.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_lanjian);

virtual void create()
{
	set_name("剑兰", "lan jian");
	set("long","这是个容貌姣好的女子, 瓜子脸蛋,眼如点漆, 清秀绝俗.你总觉得在哪见过她.");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");
 	set("icon",girl2);
	
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	
	set("combat_exp", 50000);
	set("score", 10000);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("hand",70);
	set_skill("strike", 100);
	set_skill("sword",80);
	
	set_skill("zhemei_shou",80);
	set_skill("liuyang_zhang",80);
	set_skill("tianyu_qijian",100);
	set_skill("yueying_wubu",80);
	set_skill("bahuang_gong", 70);
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");
	
	create_family("灵鹫宫",3,"弟子");
	
	carry_object("qingyi")->wear();
	carry_object("doupeng")->wear();
	carry_object("changjian")->wield();
	add_money(1500);
}

NPC_END;