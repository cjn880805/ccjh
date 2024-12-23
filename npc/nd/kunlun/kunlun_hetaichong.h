// hetaichong.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_hetaichong);

virtual void create()
{
	set("icon", young_man6);
	set_name("何大冲", "he taichong");
	set("title", "昆仑派掌门");
	set("nickname", "铁琴先生");
	set("long",
		"他就是昆仑派掌门、名扬江湖的铁琴先生何大冲。\n"
		"虽然年纪已大，但仍然看得出他年轻时英俊潇洒。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_hp", 2500);
	set("hp", 2500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 50);
	set("combat_exp", 1200000);
	set("score", 40000);

	set_skill("taiji_shengong", 80);
	set_skill("art", 100);
	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("xuantian_wuji", 260);
	set_skill("dodge", 140);
	set_skill("taxue_wuhen", 260);
	set_skill("strike", 80);
	set_skill("kunlun_zhang", 180);
	set_skill("parry", 165);
	set_skill("sword", 175);
	set_skill("liangyi_jian", 165);
	set_skill("xunlei_jian", 265);
	set_skill("mantian_huayu", 265);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian_quan", 260);

	map_skill("throwing", "mantian_huayu");
	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("cuff", "zhentian_quan");
	map_skill("parry", "liangyi_jian");
	map_skill("sword", "liangyi_jian");

	prepare_skill("leg", "chuanyun_tui");
	prepare_skill("strike", "kunlun_zhang");
/*
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
                (: command("unwield qin") :),
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );
*/
	create_family("昆仑派", 4, "掌门人");
	set("class", "taoist");
/*
	set("inquiry",
		([
			"心法" : (: ask_me :),
			"苏习之" : (: ask_su :),
			"追杀" : (: ask_ding :),
		]));

	set("book_count", 1);
	set("ding_count", 18);
*/
	carry_object("changjian")->wield();
//	carry_object("pao2.c")->wear();
};
/*
void attempt_apprentice(object ob)
{
	 if((int)ob->query("shen")<0){
	 command("say 我昆仑乃是堂堂名门正派，"+RANK_D->query_respect(ob)+
				"的品德实在令人怀疑。");
	 command("say "+RANK_D->query_respect(ob)+
				"还是先回去做点善事吧。");
	 return;
	 }

	 if(ob->query("gender")=="女性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"老夫可不敢收女弟子，你去找我夫人去吧。");
	 return;
	 }

          if(ob->query("appren_hezudao", 1) == 1) {
	 command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
	 return;
	 }
    
	if(ob->query_skill("xuantian-wuji",1)<100){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"你的玄天无极功太差，我可不想收你。");
	 return;
	 }
	 command("say 好吧，我便收下你，只是你投入我门下之后，须得安心学艺。");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		  if (query("book_count") < 1)
					 return "你来晚了，本派心经已被你师兄拿走了。";
//          if(ob->query("gender")!="女性"||ob->query("per")<23)
//        	     	 return "本派心经不在我这里。";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "我这里有本「心法」，是有关吐呐吸气的，你拿回去好好钻研，有空多来找我哦";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
		 if(this_player()->query_skill("mantian-huayu",1) < 60)
           return "你如此自愿为师门效力，不枉我平时一番栽培，速速去吧";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎么又来要了？";
		  if (query("ding_count") < 1)
					 return "丧门钉已给了我派去追杀苏习之的人，你就不用去了。";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "你如此自愿为师门效力，不枉我平时一番栽培，这把丧门钉你就拿去吧。";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "你还待在这里做什么，还不快去追苏习之";
		  return "苏习之这家伙竟然敢偷看本派的两仪神剑，我派弟子必当将其追杀。";
}
*/
NPC_END;