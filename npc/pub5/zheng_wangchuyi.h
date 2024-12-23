//zheng_wangchuyi.h 王处一


NPC_BEGIN(CNzheng_wangchuyi);

virtual void create()
{
	set_name("王老五","wang laowu");
	set("gender", "男性");
	set("age", 35);
	set("class", "taoist");
	set("nickname","玉阳子");
	set("long","他就是全真七子之五王老五王真人。他身材修长，服饰整洁，三绺黑须飘在胸前，神态潇洒。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("foolid",55);	set("con", 32);
	set("dex", 30);
	set("icon",taoist);
	
	set("title","全真七子之五");
	set("chat_chance_combat", 60);
	set("chat_chance", 8);
	
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("xiantian_qigong", 220);    //先天气功
	set_skill("sword", 220);
	set_skill("quanzhen_jian",220);  //全真剑
	set_skill("dodge", 200);
	set_skill("jinyan_gong", 200);   //金雁功
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("haotian_zhang", 220);    //昊天掌
	set_skill("literate",160);
	set_skill("strike",180);
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



