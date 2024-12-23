// seng-bing3.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNshaolin_sengbing3);

virtual void create()
{
	set_name("����ɮ��", "seng bing");
	set("long",
		"����һλ��ĸߴ��׳��ɮ�ˣ����۴�׳��������Բ����\n"
		"�ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n");

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
        set("icon",young_monk);
	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("unarmed", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");

	carry_object("jiedao")->wield();
	carry_object("cloth")->wield();
}
/*
void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "������" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say ����˭��  ��ô���������������ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ���������������Ұ������\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
*/
NPC_END;