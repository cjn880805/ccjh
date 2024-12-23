NPC_BEGIN(CNPub_cungu);

virtual void create()
{
	set_name("村姑","cungu");

	set("icon", young_woman8);
	set("gender", "女性" );
	set("age", 20);
	set("long", "一个很清秀的年轻农村姑娘，挎着一只盖着布小篮子。");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 15);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
    carry_object("caomei");
    carry_object("turou");
	
};


virtual char * combat_chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "村姑说：救命呀！光天化日之下，强暴杀人呀！";
	case 1:
	case 2:
		return "村姑说：相公快来呀！这里有人要强暴我！";
	case 3:
		return "村姑说：打倒要杀害我的人！";
	}

	return "";
}

NPC_END;
