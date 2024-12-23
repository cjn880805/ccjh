//yu.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_yu);

virtual void create()
{
	set_name("������","yu lianzhou");
	set("nickname", "�䵱����");
	set("long","������������Ķ����������ۡ���������ʮ�꣬��Ŀ��࣬�������ء������䵱�����������ڶ�������ȴ�����");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("foolid",132);	set("str", 30);
	set("int", 30);
	set("con", 32);
	set("dex", 32);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 15500);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_force", 150);
	set("combat_exp", 2500000);
	set("score", 400000);

	set_skill("force", 220);
	set_skill("taiji_shengong", 220);
	set_skill("dodge", 190);
	set_skill("tiyunzong", 190);
	set_skill("unarmed", 230);
	set_skill("taiji_quan", 230);
	set_skill("parry", 230);
	set_skill("sword", 250);
	set_skill("taiji_jian", 250);
	set_skill("taoism", 200);
	set_skill("literate", 150);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("�䵱��", 2, "����");

	set("chat_chance_combat", 40);

	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword chan",1);
		break;
	case 1:
		perform_action("sword lian",1);
		break;
	case 2:
		perform_action("sword sui",1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("repute") < 10000 )
	 {
		say("���䵱���������������ɣ��Ե���Ҫ���ϡ�",player);
		say("���ڵ��з����Ƿ����ò�����",player);
		SendMenu(player);
		return;
	 }
	if (player->query_skill("taiji_shengong",1) < 80 ||player->query_skill("force",1) < 80 )
	{
		say("���䵱����ע���ڹ��ķ���Ӧ�����ڹ��϶��µ㹦��?",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("taoism",1) < 80)
	{
		say("ϰ����Ϊ��ǿ����,һζ�������ǲ���ȡ��!",player);
		say("�ҿ��㻹��Ҫ���������Է�����������,�������ĵ����ķ�",player);
		SendMenu(player);
		return;
	}
	say("�ðɣ��Ҿ��������ˡ�");
	say("ϣ�����ܺú��ù�,�������䵱����!");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	player->set("class", "taoist");
}

NPC_END;