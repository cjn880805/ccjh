// yan.c
//sound 2001-07-16

NPC_BEGIN(CNmurong_yan);

virtual void create()
{
	set_name("������", "yan mama");
	set("gender", "Ů��");
	set("age", 50);      
	set("title","���ʷ�����");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",old_woman);
	
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("no_get","��û�취���������");
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	set_skill("blade",70);
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("gangdao")->wield();
	
	set_inquiry("����", "������٢��ɽׯ�Ļ������¡�");
	set_inquiry("����", "�����ǻ��ʷ���ר�Űѷ����ô������������ʡ�");
	set_inquiry("����",  "���һ���նε�С�Ӵ����������ˡ�");
          
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
        && ( (fam = ob->query("family")) && fam["family_name"] != "����Ľ��" ) )
	{
		command("say �������ʲ�̫�����������������������ʰɣ�����\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}
*/
NPC_END;