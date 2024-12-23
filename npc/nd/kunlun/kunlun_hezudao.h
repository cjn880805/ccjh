// hezudao.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_hezudao);

virtual void create()
{
	set("icon", young_man5);
	set_name("何不谈", "he zudao");
	set("title", "昆仑派开山祖师");
	set("nickname", "昆仑三圣");
	set("long",
		"他就是昆仑派开山祖师，号称琴剑棋三绝的“昆仑三圣”。\n"
		"长脸深目，瘦骨棱棱，约莫三十岁左右年纪。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0l);
	set("str", 27);
	set("int", 40);
	set("con", 40);
	set("dex", 28);

	set("max_hp", 4000);
	set("hp", 4000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 2500000);
	set("score", 400000);
/*
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		 (: perform_action, "strike.diezhang" :)
	}));
*/
	set_skill("art", 300);
        set_skill("literate", 280);
	set_skill("force", 185);
	set_skill("xuantian_wuji", 320);
	set_skill("dodge", 200);
	set_skill("kunlun_shenfa", 300);
	set_skill("strike", 180);
	set_skill("kunlun_zhang", 300);
	set_skill("chuanyun_tui", 300);
	set_skill("zhentian_quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 210);
	set_skill("cuff", 200);
	set_skill("leg", 210);
	set_skill("liangyi_jian", 300);
	set_skill("throwing", 250);
	set_skill("taiji_shengong", 180);
	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "kunlun_shenfa");
	map_skill("strike", "kunlun_zhang");
	map_skill("parry", "art");
	map_skill("sword", "liangyi_jian");
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
	create_family("昆仑派", 1, "开山祖师");
//	set("class", "taoist");

//	carry_object("jwqin")->wield();
	carry_object("changjian")->wield();
};
/*
void attempt_apprentice(object ob)
{
                mapping skill;
		string *skl;
                int i;

//		if(ob->query("kar") < 20)
//		return;

//		if(ob->query_int() < 32 ) {
//		command("say 弹琴下棋需要灵性极高的人才可以领悟其真谛，不致与武功背道而驰。");
//		command("say "+RANK_D->query_respect(ob)+"还是先回去多读点书吧。");
//		return;
//	}
                if ((int)ob->query_skill("xuantian-wuji", 1) < 85) {
		command("say 琴棋书画虽为小技，但也需内力融入其中。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先在玄天无极功上多下点功夫？");
		return;
	}

		if ((int)ob->query("max_mp", 1) < 500) {
		command("say 内力不够，一心二用则极容易走火入魔。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先好好修炼内力？");
		return;
	}

//        	skill = ob->query_skills();
//		skl = keys(skill);
//		i = sizeof(skl);
//		while (i--) {
//              if (skill[skl[i]] < 80)
//                command("say " + RANK_D->query_respect(ob) + 
//		        "是否在" + 
//		        CHINESE_D->chinese(skl[i]) + 
//		        "上多下些功夫？");
//        	return;
//	}
	        
		command("say 看来你也是性情中人，我就教你一些琴剑棋的知识吧。");
		command("recruit "+ob->query("id"));

if (!ob->query("appren_hezudao"))
{
                ob->set("appren_hezudao", 1);
		ob->add("int", 1);
		ob->set_skill("art", ob->query_skill("literate"));
}
//		ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
}
*/
NPC_END;