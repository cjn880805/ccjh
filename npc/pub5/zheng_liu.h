//zheng_liu.c 刘处玄

NPC_BEGIN(CNzheng_liu);

virtual void create()
{
	set_name("刘在玄", "liu zaixuan");
	set("gender", "男性");
	set("age", 38);
	set("class", "taoist");
	set("nickname","长生子");
	set("long", "他就是全真三徒刘在玄刘真人，他身材瘦小，但顾盼间自有一种威严气概。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 30);
	set("con", 28);
	set("dex", 30);
	
	set("title","全真七子之三");
	set("foolid",29);
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("sword", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 220);    //先天气功
	set_skill("quanzhen_jian",220);  //全真剑
	set_skill("jinyan_gong", 200);   //金雁功
	set_skill("haotian_zhang", 220);    //昊天掌

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 2, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
}
void die()
{
	CFightRoom * obj=(CFightRoom *)environment();
	revive(1);
	message_vision("\n$N见势不秒，一个闪身，跳出阵中，你刚想追击，只件几道剑光迎面刺来，只得作罢，旁边一人立即补上。", this);
	obj->add("zheng/count",-1);

	if(EQUALSTR(obj->querystr("zheng/friend1_name"), this->name(1)))
	{
		obj->del("zheng/friend1_idx");
		obj->del("zheng/friend1_name");
	}
	else if(EQUALSTR(obj->querystr("zheng/friend2_name"), this->name(1)))
	{
		obj->del("zheng/friend2_idx");
		obj->del("zheng/friend2_name");
	}
	else
	{
		obj->del("zheng/friend3_idx");
		obj->del("zheng/friend3_name");
	}
	destruct(this);
}
NPC_END;



