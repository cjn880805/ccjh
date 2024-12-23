//famu.h
//lanwood 2001-02-07

NPC_BEGIN(CNwudang_famu);

virtual void create()
{
	set_name("��ľ����", "famu daozhang");
	set("long", "�����䵱ɽ�ķ�ľ����, רΪ�����ṩľ�ġ�");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("foolid",121);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("taiji_dao", 25);
	set_skill("taoism", 20);

//	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji_dao");

	create_family("�䵱��", 4, "����");

	carry_object("gangdao")->wield();
}

NPC_END;