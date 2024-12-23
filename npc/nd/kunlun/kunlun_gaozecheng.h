// gaozecheng.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_gaozecheng);

virtual void create()
{
	set("icon", young_man4);
	set_name("�����", "gao zecheng");
	set("long",
		"������ɫ���ۣ�����б�峤������ʮ�˾�����͡�\n"
		"���ֺ�˪��һ��Ҫ�������ǵ�ģ����\n");
	set("gender", "����");
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

	create_family("������", 5, "����");

        carry_object("changjian")->wield();
//        carry_object("pao3")->wear();
};
/*
void attempt_apprentice(object ob)
{
     if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ʦ����׼����Ů���ӣ���ȥ����ʦ械ɡ�");
	 return;
	 }


	 if(ob->query("appren_hezudao", 1) == 1) {
	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
	 return;
	 }

	 command("say ��Ȼ"+RANK_D->query_respect(ob)+
				"Ľ������֮����ǧ����������������Ե���������Ӣ��,�Ҿ�������ɡ�");
	 command("recruit " + ob->query("id"));
}
*/
NPC_END;