// lingjiu_nvlang.h 蒙面女郎

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_nvlang);

virtual void create()
{
	set_name("蒙面女郎", "nv lang");
	set("long","这是个身材娇好的女郎, 轻纱遮面,一双秀目中透出一丝杀气。");
	set("gender", "女性");
	set("age", 20);
	
	set("attitude", "peaceful");
 	set("icon",young_woman11);
	
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 5000);
	set("max_hp", 5000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 100000);
	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",150);
	set_skill("strike", 150);
	set_skill("sword",150);
	
	set_skill("zhemei_shou",100);
	set_skill("liuyang_zhang",100);
	set_skill("tianyu_qijian",150);
	set_skill("yueying_wubu",100);
	set_skill("bahuang_gong", 100);
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");
	
	create_family("灵鹫宫",3,"弟子");
	set_inquiry("草药","我正在制作一味药，缺了最关键的茯苓根。");
	
	carry_object("qingyi")->wear();
	carry_object("doupeng")->wear();
	carry_object("changjian")->wield();
	add_money(1500);
	set("no_huan",1);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "caogeng") || DIFFERSTR(ob->querystr("name"), "草根" ))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "影月牌", "yingyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}



NPC_END;