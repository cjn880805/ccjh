// gaozecheng.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_gaozecheng);

virtual void create()
{
	set("icon", young_man4);
	set_name("低则就", "gao zecheng");
	set("long",
		"他穿青色长袍，背上斜插长剑，二十八九岁年纪。\n"
		"脸罩寒霜，一副要惹事生非的模样。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_hp", 600);
	set("hp", 600);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("xuantian_wuji", 85);
	set_skill("dodge", 80);
	set_skill("taxue_wuhen", 90);
	set_skill("parry", 80);
	set_skill("sword", 85);
	set_skill("xunlei_jian", 95);
	set_skill("cuff", 80);
	set_skill("zhentian_quan", 90);

	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("sword", "xunleijian");
	map_skill("cuff", "zhentian_quan");
	prepare_skill("cuff", "zhentian_quan");

	create_family("昆仑派", 5, "弟子");

        carry_object("changjian")->wield();
//        carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
     if(ob->query("gender")=="女性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"师傅不准我收女弟子，你去找我师姊吧。");
	 return;
	 }


	 if(ob->query("appren_hezudao", 1) == 1) {
	 command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
	 return;
	 }

	 command("say 既然"+RANK_D->query_respect(ob)+
				"慕昆仑派之名，千里而来，我昆仑派自当广纳天下英才,我就收下你吧。");
	 command("recruit " + ob->query("id"));
}
*/
NPC_END;