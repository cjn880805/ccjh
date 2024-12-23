// hezudao.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_hezudao);

virtual void create()
{
	set("icon", young_man5);
	set_name("�β�̸", "he zudao");
	set("title", "�����ɿ�ɽ��ʦ");
	set("nickname", "������ʥ");
	set("long",
		"�����������ɿ�ɽ��ʦ���ų��ٽ��������ġ�������ʥ����\n"
		"������Ŀ���ݹ����⣬ԼĪ��ʮ��������͡�\n");
	set("gender", "����");
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
	create_family("������", 1, "��ɽ��ʦ");
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
//		command("say ����������Ҫ���Լ��ߵ��˲ſ������������У��������书�������ۡ�");
//		command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������ɡ�");
//		return;
//	}
                if ((int)ob->query_skill("xuantian-wuji", 1) < 85) {
		command("say �����黭��ΪС������Ҳ�������������С�");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������޼����϶��µ㹦��");
		return;
	}

		if ((int)ob->query("max_mp", 1) < 500) {
		command("say ����������һ�Ķ����������߻���ħ��");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ���Ⱥú�����������");
		return;
	}

//        	skill = ob->query_skills();
//		skl = keys(skill);
//		i = sizeof(skl);
//		while (i--) {
//              if (skill[skl[i]] < 80)
//                command("say " + RANK_D->query_respect(ob) + 
//		        "�Ƿ���" + 
//		        CHINESE_D->chinese(skl[i]) + 
//		        "�϶���Щ����");
//        	return;
//	}
	        
		command("say ������Ҳ���������ˣ��Ҿͽ���һЩ�ٽ����֪ʶ�ɡ�");
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