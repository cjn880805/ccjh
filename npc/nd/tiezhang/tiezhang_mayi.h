// mayi.c
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_mayi);

virtual void create()
{
	set_name("���³���", "mayi zhanglao");
	set("long",
		"����һ����Լ��Ѯ�����ߣ���ͷ���������ް߰ס�\n"
		"�������̫��Ѩ�߸߹���΢�յ�˫Ŀ��ʱ�����������������ƺ�����������\n");
	
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 60);
	set("shen_type", 1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("icon",old_man2);
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 120);
	set("combat_exp", 500000);
	set("score", 10000);
	
	set_skill("force", 100);
	set_skill("guiyuan_tunafa", 100);
	set_skill("dodge", 100);
	set_skill("shuishangpiao", 100);
	set_skill("strike", 100);
	set_skill("tiezhang_zhangfa", 100);
	set_skill("parry", 100);
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	
	carry_object("cloth")->wear();
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
		&& !present("tiezhang ling", ob) 
		&& ( (fam = ob->query("family")) && fam["family_name"] != "���ư�" ) 
		&& (int)ob->query("combat_exp", 1) >= 10000 ) 
	{
		if( !ob->query_temp("warned") ) {
			command("say վס���㲻�����ư���ӣ������ڴ˾�������");
			command("say �㻹�������뿪�˵ذɣ���Ȼ�����Ҫ���㲻�����ˣ���");
			command("hehe");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
		else {
			command("say ���ò��ͷ��ˣ����ҵ����ư�����Ұ������\n");
			remove_call_out("hiting_ob");
			call_out("hiting_ob", 1, ob);
		}
	}       
	
}
int hiting_ob(object ob)
{
	   object me;
	   me=this_object();
	   ob->kill_ob(me);
	   me->fight_ob(ob);
}
*/
NPC_END;