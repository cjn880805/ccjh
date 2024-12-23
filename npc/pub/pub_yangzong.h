// pub_yangzong.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_yangzong);

virtual void create()
{
	set_name("央宗", "yang zong" );

	set("icon", banditi);
	set("long","他是一位藏族同胞。");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	
	set("combat_exp", 5000);
	set("score", 1000);
	
	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	carry_object("shuzhi")->wield();
	carry_object("sengmao")->wear();
	carry_object("sengxie")->wear();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"央宗合什为礼，说道：阿弭佗佛！%s，贫僧这厢有礼了。",query_respect(ob) );
}
NPC_END;