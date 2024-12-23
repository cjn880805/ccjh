//zhongxiaoer.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zhongxiaoer);

virtual void create()
{
	set_name("钟小二","zhongxiaoer");
	
	set("icon", boy1);
	set("gender", "男性" );
	set("age", 3);
	set("long", "他是钟阿四的二儿子，几只狼狗在追着撕咬他。");
	set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
};


NPC_END;
