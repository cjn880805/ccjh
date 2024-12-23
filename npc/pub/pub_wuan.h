//pub_wuan.h
//wuqing 2002-02-15

NPC_BEGIN(CNpub_wuan);

virtual void create()
{
	set_name("吴安", "wu an");
	set("long","这是一个二十五六岁的年轻人, 浓眉大眼,自命风流. ");
	set("title", "采花郎");
	set("gender", "男性");
	set("per", 36);
	set("age", 26);
	set("shen_type",1);
	set("attitude", "peaceful");
	set("icon",young_man1);

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("max_hp", 12000);
	
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 120);

	set("combat_exp", 2500000);
	set_skill("force", 220);
	set_skill("unarmed", 250);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("hand",220);
	set_skill("strike", 220);

	set_skill("zhemei_shou",220);
	set_skill("liuyang_zhang",220);
	set_skill("yueying_wubu",200);
	set_skill("bahuang_gong", 230);
    set_skill("tianyu_qijian", 220);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword", "tianyu_qijian");

	set("no_kill",1);//不被列入万劫谷的任务中
	
	carry_object("changjian")->wield();
//	carry_object("changpao")->wear();
};

virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}
	
NPC_END;



