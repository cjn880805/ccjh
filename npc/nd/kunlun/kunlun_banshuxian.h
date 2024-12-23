// banshuxian.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_banshuxian);

virtual void create()
{
	set("icon", young_woman12);
	set_name("�����", "ban shuxian");
	set("title", "���������ŷ���");
	set("long",
		"���������������š����ｭ��������������̫��ķ��ˡ�����һ����ĸߴ�İ���Ů�ӣ�ͷ�����ף�˫Ŀ������ü�ļ����ɷ����");
	set("gender", "Ů��");
	set("age", 44);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 50);
	set("combat_exp", 800000);
	set("score", 40000);

	set_skill("art", 120);
	set_skill("literate", 120);
	set_skill("force", 155);
	set_skill("xuantian_wuji", 160);
	set_skill("dodge", 145);
	set_skill("taxue_wuhen", 155);
	set_skill("strike", 60);
	set_skill("kunlun_zhang", 65);
	set_skill("parry", 160);
	set_skill("sword", 170);
	set_skill("leg", 140);
	set_skill("chuanyun_tui", 260);
	set_skill("liangyi_jian", 170);
	set_skill("xunlei_jian", 260);
	set_skill("mantian_huayu", 260);
	set_skill("throwing", 165);
	set_skill("taiji_shengong", 200);
	
	map_skill("throwing", "mantian_huayu");
	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("leg", "chuanyun_tui");
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
	create_family("������", 4, "���ŷ���");
	set("class", "taoist");
/*
	set("inquiry",
		([
			"�ؼ�" : (: ask_me :),
		]));
	set("book_count", 1);
*/
	carry_object("changjian")->wield();
//	carry_object("pao2.c")->wear();
};
/*
void attempt_apprentice(object ob)
{
	 if((int)ob->query("shen")<0){
	 command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+
				"��Ʒ��ʵ�����˻��ɡ�");
	 command("say "+RANK_D->query_respect(ob)+
				"�����Ȼ�ȥ�������°ɡ�");
	 return;
	 }

	 if(ob->query("gender")=="����"){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"������Щ�������Ҽ��˾ͷ���������߿���");
	 return;
	 }

          if(ob->query("appren_hezudao", 1) == 1) {
	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
	 return;
	 }
    
	if(ob->query_skill("xuantian-wuji",1)<100){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"��������޼���̫��ҿɲ������㡣");
	 return;
	 }
	 command("say �ðɣ��Ժ���͸���ѧ�书�ɣ�����ð���ѧ�գ�����������");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
//			 if(ob->query("gender")=="����")
//        	     	 return "�����߿����ҿ���������Щ�����˾ͷ���";
		  if (query("book_count") < 1)
					 return "�������ˣ������澭�ѱ���ʦ�������ˡ�";
		  add("book_count", -1);
		  ob = new("/d/kunlun/obj/lyj-book.c");
		  ob->move(this_player());
		  return "��ʦ���������Ȿ�����ǽ��ĵá������û�ȥ�ú����С�";
}
*/
NPC_END;
