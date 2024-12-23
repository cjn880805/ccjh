// yulingzi.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_yulingzi);

virtual void create()
{
	set("icon", taoistess);
	set_name("������", "yuling zi");
	set("long", "�������ɵ�������ӣ�������������ķ���������Ͷ�����ŵ�����֮�⡣");
	set("gender", "Ů");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);
	set("per", 28);

	set("max_hp", 850);
	set("hp", 850);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 30);
	set("combat_exp", 380000);
	set("score", 4000);

	set_skill("force", 95);
	set_skill("xuantian_wuji", 105);
	set_skill("dodge", 95);
	set_skill("taxue_wuhen", 105);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei_jian", 105);
	set_skill("leg", 90);
	set_skill("chuanyun_tui", 100);
	set_skill("throwing", 80);
	set_skill("mantian_huayu", 95);


	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
	map_skill("sword", "xunlei_jian");
	map_skill("leg", "chuanyun_tui");
	map_skill("sword", "xunlei_jian");

	prepare_skill("leg", "chuanyun_tui");

	create_family("������", 5, "����");

	carry_object("changjian")->wield();
//	carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
      if(ob->query("gender")=="����"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ʦ����׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
	 return;
	 }

if(ob->query_skill("xuantian-wuji",1)<60){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"��������޼���̫��ҿɲ������㡣");
	 return;
	 }

	 if(ob->query("appren_hezudao", 1) == 1) {
	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
	 return;
	 }
	 command("say ��Ȼ"+RANK_D->query_respect(ob)+
				"��ôŬ�����Ҿ�������ɡ�");
	 command("recruit " + ob->query("id"));
}
*/
NPC_END;
