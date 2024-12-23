// jiangtao.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_jiangtao);

virtual void create()
{
	set("icon", young_man2);
	set_name("蒋浪", "jiang tao");
	set("long",
		"他穿青色长袍，背上斜插长剑，二十八九岁年纪。\n"
		"脸罩寒霜，一副要惹事生非的模样。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 26);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 65);
	set_skill("xuantian_wuji", 60);
	set_skill("dodge", 65);
	set_skill("taxue_wuhen", 60);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei_jian", 65);
	set_skill("cuff", 55);
	set_skill("zhentian_quan", 70);

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

         if(ob->query("appren_hezudao", 1) == 1) {
	command("say 师祖怎敢开如此玩笑，晚辈却是万万不敢的！");
	return;
	}

	command("say 好吧，我就收下你，教你一些皮毛功夫。");
	command("recruit " + ob->query("id"));
}
*/
NPC_END;