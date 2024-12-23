//poorman.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_poorman);

virtual void create()
{
	set_name("穷汉","poorman");
	
	set("icon", young_man4);
	set("gender", "男性" );
	set("age", 33);
	set("long", "一个骨瘦如柴，满脸菜色的穷汉。");
	set("attitude", "friendly");
	set("combat_exp", 250);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	
	set("chat_chance", 15);
	carry_object("cloth")->wear();
	
	
};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "穷汉懒洋洋地打了个哈欠。";
	case 1:
		return "穷汉说道：那些蒙古鞑子害得我家破人亡。";
	}
	return "";
}

NPC_END;
