//qingxu.h
//code by zwb
//12-16

NPC_BEGIN(CNwudang_qingxu);

virtual void create()
{
	set_name("�������", "qingxu daozhang");
	set("long","�����������۵ĵ�������������������ʮ���꣬���ܸ���۵����¡�ר�������￴�ر��ɵĸ��ֵ���");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("foolid",125);	set("dex", 25);
	set("icon",taoist);	
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_force", 30);

	set("combat_exp", 70000);
	set("score", 8500);

	set_skill("force", 60);
	set_skill("taiji_shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 60);
	set_skill("taiji_quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji_jian", 60);
	set_skill("taoism", 60);
  	set_skill("literate", 80);

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
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * ob;
	if (DIFFERSTR(player->querystr("family/family_name"), "�䵱��"))
		return "���뱾��������������֪�˻��Ӻ�̸��";
    if (npc->query("book_count") < 1)
		return "�������ˣ����ɵĵ����澭���ڴ˴���";
    npc->add("book_count", -1);
    ob = load_item("daodejing_ii");
    ob->move(player);
    return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}

NPC_END;