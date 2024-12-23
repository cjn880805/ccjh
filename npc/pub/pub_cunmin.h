NPC_BEGIN(CNPub_cunmin);

virtual void create()
{
	set_name("村民","cunmin");

	set("icon", banditi);
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个魁梧的庄稼汉子。");
	set("attitude", "friendly");
	set("combat_exp", 500);
	set("repute", 100);
	set("shen_type", 1);
	set("str", 22);
	set("dex", 18);
	set("con", 18);
	set("int", 13);
	set("chat_chance", 15);
	
	carry_object("cloth")->wear();
	add_money(100);
	
	
};

virtual char * chat_msg(CChar * me)
{
	switch(random(2))
	{
	case 0:
		return "村民说道：多亏全真教的道爷们，这山上咬庄稼的獾子全让他们给赶跑了。";
	case 1:
		return "村民说道：今年的收成不错，我得跟全真教的道爷们送点儿去，请他们尝尝鲜。";
	}
	return "";
}

NPC_END;
