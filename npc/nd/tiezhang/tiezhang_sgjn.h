// sgjn.c �Ϲٽ���
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_sgjn);

virtual void create()
{
	set_name("�Ϲ��Ͻ�", "shangguan jiannan");
	set("nickname", "����ˮ��Ư");
	set("long", 
		"��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣���������\n"
		"֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�\n"
		"ֻ�Ǻ�����Ȼ�����伣����֪�����ˡ�\n");
	set("gender", "����");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 45);
	set("int", 40);
	set("con", 48);
	set("dex", 44);
	set("icon",old_man1);
	
	set("max_hp", 6000);
	set("hp", 6000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 200);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 250);
	set_skill("guiyuan_tunafa", 250);
	set_skill("dodge", 200);
	set_skill("shuishangpiao", 250);
	set_skill("strike", 250);
	set_skill("tiezhang_zhangfa", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("tiexue_hammer",250);
	set_skill("duanyun_fu", 250);
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("���ư�", 13, "����");
	
	carry_object("cloth")->wear();
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") < 50000) 
	{
		command("hehe");
		command("say ���Ϲٽ��Ͽɲ����ĵز���������ͽ�ܡ�");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
*/
NPC_END;