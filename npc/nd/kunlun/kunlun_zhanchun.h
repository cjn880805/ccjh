// zhanchun.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_zhanchun);

virtual void create()
{
	set("icon", young_woman6);
	set_name("詹秋", "zhan chun");
	set("long", "她是何太冲最喜欢的弟子，长得倒也颇为俏丽。");
	set("gender", "女性");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
	set("per", 26);

	set("hp", 600);
	set("max_hp", 600);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 40);
	set_skill("xuantian_wuji", 65);
	set_skill("dodge", 60);
	set_skill("taxue_wuhen", 65);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei_jian", 65);
	set_skill("leg", 50);
	set_skill("chuanyun_tui", 60);

	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("leg", "chuanyun_tui");
	map_skill("sword", "xunlei_jian");

	prepare_skill("leg", "chuanyun_tui");

	create_family("昆仑派", 5, "弟子");

	carry_object("changjian")->wield();
//	carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
if(ob->query("gender")=="男性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"师傅不准我收男弟子，你去找我师兄去吧。");
	 return;
	 }

         if(ob->query("appren_hezudao", 1) == 1) {
	command("say 师祖怎敢开如此玩笑，晚辈却是万万不敢的！");
	return;
	}

	command("say 好吧，我就收下你，教你一些皮毛功夫。");
	command("recruit " + ob->query("id"));
}
*/
NPC_END;