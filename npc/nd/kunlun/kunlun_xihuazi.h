// xihuazi.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_xihuazi);

virtual void create()
{
	set("icon", taoist_with_sword);
	set_name("东华子", "xi huazi");
	set("long", "他是昆仑派第五代弟子，满腮虬髯，性子十分暴躁。");
	set("gender", "男性");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_hp", 800);
	set("hp", 800);
	set("max_mp", 1500);
	set("mp_factor", 30);
	set("combat_exp", 400000);
	set("score", 1000);

	set_skill("force", 95);
	set_skill("xuantian_wuji", 105);
	set_skill("dodge", 80);
	set_skill("taxue_wuhen", 100);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei_jian", 105);
	set_skill("cuff", 105);
	set_skill("zhentian_quan", 110);
	set_skill("throwing", 80);
	set_skill("mantian_huayu", 95);


	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("sword", "xunlei_jian");
	map_skill("cuff", "zhentian_quan");
	prepare_skill("cuff", "zhentian_quan");

	create_family("昆仑派", 5, "弟子");

	carry_object("changjian")->wield();
//	carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="女性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"师傅不准我收女弟子，你去找我师姊去吧。");
	 return;
	 }
	if(ob->query_skill("xuantian-wuji",1)<60){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"你的玄天无极功太差，我可不想收你。");
	 return;
	 }

	 if(ob->query("appren_hezudao", 1) == 1) {
	 command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
	 return;
	 }
	 command("say 既然"+RANK_D->query_respect(ob)+
				"这么努力，我就收下你吧。");
	 command("recruit " + ob->query("id"));
}
*/
NPC_END;


