//shizhe1.h
//code by sound
//2001-07-10

NPC_BEGIN(CNxiakedao_shizhe1);

virtual void create()
{
	set_name("侍者1","shizhe");
	
	set("icon", waiter);
	set("gender", "男性" );
	set("age", 14);
	set("long", "一个身着黄衣的汉子。");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("str", 20);
	set("dex", 25);
	set("con", 20);
	set("int", 25);
	set("attitude", "friendly");
	create_family("侠客岛", 2, "弟子");
	
	carry_object("cloth")->wear();
	
};

NPC_END;
