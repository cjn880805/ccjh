// zhanchun.c (kunlun)
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNkunlun_zhanchun);

virtual void create()
{
	set("icon", young_woman6);
	set_name("ղ��", "zhan chun");
	set("long", "���Ǻ�̫����ϲ���ĵ��ӣ����õ�Ҳ��Ϊ������");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
	set("per", 26);

	set("hp", 600);
	set("max_hp", 600);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 40);
	set_skill("xuantian_wuji", 65);
	set_skill("dodge", 60);
	set_skill("taxue_wuhen", 65);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei_jian", 65);
	set_skill("leg", 50);
	set_skill("chuanyun_tui", 60);

	map_skill("force", "xuantian_wuji");
	map_skill("dodge", "taxue_wuhen");
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

         if(ob->query("appren_hezudao", 1) == 1) {
	command("say ʦ�����ҿ������Ц����ȴ�����򲻸ҵģ�");
	return;
	}

	command("say �ðɣ��Ҿ������㣬����һЩƤë����");
	command("recruit " + ob->query("id"));
}
*/
NPC_END;