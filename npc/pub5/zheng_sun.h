//zheng_sun.h 孙不二


NPC_BEGIN(CNzheng_sun);

virtual void create()
{
	set_name("孙说一", "sun suoyi");
	set("gender", "女性");
	set("age", 33);
	set("class", "taoist");
	set("nickname", "清净散人");
	set("long",  "她就是全真教二代弟子中唯一的女弟子孙说一孙真人。她本是马玉入道前的妻子，道袍上绣着一个骷髅头。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("foolid",35);
	set("title","全真七子之末");
	set("chat_chance_combat", 60);
	
	set("hp", 4000);
	set("max_hp", 12000);
	
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 180);
	set_skill("sword", 180);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("unarmed",180);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 200);    //先天气功
	set_skill("quanzhen_jian",200);  //全真剑
	set_skill("jinyan_gong", 180);   //金雁功
	set_skill("haotian_zhang", 200);    //昊天掌

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



