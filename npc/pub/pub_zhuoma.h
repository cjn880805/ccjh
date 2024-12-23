// pub_zhuoma.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhuoma);


virtual void create()
{
	set_name("卓玛", "zhuo ma");

	set("icon", young_woman3);
	set("long",	"她是一位藏族女同胞。");
	set("gender", "女性");
	set("age", 25);
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
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"卓玛合什为礼，说道：阿弭佗佛！%s，贫尼这厢有礼了。",query_respect(ob));
}
NPC_END;