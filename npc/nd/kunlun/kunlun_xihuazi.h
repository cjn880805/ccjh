// xihuazi.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_xihuazi);

virtual void create()
{
	set("icon", taoist_with_sword);
	set_name("������", "xi huazi");
	set("long", "���������ɵ�������ӣ�������ף�����ʮ�ֱ��ꡣ");
	set("gender", "����");
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

	create_family("������", 5, "����");

	carry_object("changjian")->wield();
//	carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ʦ����׼����Ů���ӣ���ȥ����ʦ�ȥ�ɡ�");
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


