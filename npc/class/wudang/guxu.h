//guxu.h
//code by zwb
//1-15

NPC_BEGIN(CNwudang_guxu);

virtual void create()
{
	set_name("�������", "guxu daozhang");
	set("long","�����������۵ĵ��ӹ����������������ʮ�꣬�����䵱�ɵ����¡�");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("foolid",123);	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 4500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_force", 50);

	set("combat_exp", 700000);
	set("score", 85000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji_shengong", 80);
	set_skill("taiji_jian", 80);
	set_skill("taiji_quan", 80);
	set_skill("tiyunzong", 80);
	set_skill("taoism", 80);
  	set_skill("literate", 60);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("�䵱��", 3, "����");
	set("class", "taoist");

	set_inquiry("���¾�",ask_me);
                                 
	set("book_count", 1);

	carry_object("changjian")->wield();
	carry_object("greenrobe")->wear();
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (player->query("betrayer") > 1 && DIFFERSTR(player->querystr("family/family_name"), "�䵱��"))
	{ 
		say(" ����������������������£�ƶ���������ɱ������ʾ���ˣ�",player);
		SendMenu(player);
		kill_ob(player);
		return ;  
	}

	if (player->query("repute") < 0) 
	{
		say("���䵱���������������ɣ��Ե���Ҫ���ϡ�",player);
		say("���ڵ��з������û�������",player);
		SendMenu(player);
		return;
	}
	say(" �ðɣ�ƶ�����������ˡ�",player);
	SendMenu(player);
	command(snprintf(msg,255,"recruit %ld",player->object_id()));
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * ob;
	if (DIFFERSTR(player->querystr("family/family_name"), "�䵱��"))	//PARTY CHANGED TO FAMILY LANWOOD 2001-05-25
		return "���뱾��������������֪�˻��Ӻ�̸��";
    if (npc->query("book_count") < 1)
		return "�������ˣ����ɵĵ����澭���ڴ˴���";
    npc->add("book_count", -1);
    ob = load_item("daodejing_ii");
    ob->move(player);
    return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}


NPC_END;