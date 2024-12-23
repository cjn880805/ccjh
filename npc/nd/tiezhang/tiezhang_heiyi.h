// heiyi.c
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_heiyi);

virtual void create()
{
	set_name("���°���", "heiyi bangzhong");
	set("long", "����һ�����н�׳�ĺ��ӣ����۴�׳��������Բ�����������ࡣ");
	
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 30);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("icon",young_man4);
	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);
	
	set_skill("force", 40);
	set_skill("guiyuan_tunafa", 40);
	set_skill("dodge", 40);
	set_skill("shuishangpiao", 40);
	set_skill("strike", 40);
	set_skill("tiezhang_zhangfa", 40);
	set_skill("parry", 40);
	
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
		&& ( (fam = ob->query("family")) && fam["family_name"] != "���ư�")
		&& (int)ob->query("combat_exp", 1) >= 10000 ) 
	{
		if( !ob->query_temp("warned") ) {
			command("say վס���㲻�����ư���ӣ������ڴ˾�������");
			command("say ʶ��ľͿ�����ǵ�үү���𣬴����Ĺ��ȣ���");
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