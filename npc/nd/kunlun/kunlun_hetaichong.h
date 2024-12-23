// hetaichong.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_hetaichong);

virtual void create()
{
	set("icon", young_man6);
	set_name("�δ��", "he taichong");
	set("title", "����������");
	set("nickname", "��������");
	set("long",
		"���������������š����ｭ�������������δ�塣\n"
		"��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
	set("gender", "����");
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
	create_family("������", 4, "������");
	set("class", "taoist");
/*
	set("inquiry",
		([
			"�ķ�" : (: ask_me :),
			"��ϰ֮" : (: ask_su :),
			"׷ɱ" : (: ask_ding :),
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
	 command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+
				"��Ʒ��ʵ�����˻��ɡ�");
	 command("say "+RANK_D->query_respect(ob)+
				"�����Ȼ�ȥ�������°ɡ�");
	 return;
	 }

	 if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"�Ϸ�ɲ�����Ů���ӣ���ȥ���ҷ���ȥ�ɡ�");
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
	 command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
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
		  if (query("book_count") < 1)
					 return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
//          if(ob->query("gender")!="Ů��"||ob->query("per")<23)
//        	     	 return "�����ľ����������";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "�������б����ķ��������й����������ģ����û�ȥ�ú����У��пն�������Ŷ";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
		 if(this_player()->query_skill("mantian-huayu",1) < 60)
           return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬����ȥ��";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������ô����Ҫ�ˣ�";
		  if (query("ding_count") < 1)
					 return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬���ɥ�Ŷ������ȥ�ɡ�";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "�㻹����������ʲô��������ȥ׷��ϰ֮";
		  return "��ϰ֮��һﾹȻ��͵�����ɵ������񽣣����ɵ��ӱص�����׷ɱ��";
}
*/
NPC_END;