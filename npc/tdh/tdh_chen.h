// chen.c �½���

NPC_BEGIN(CNtdh_chen);

void create()
{
	set_name("�½���", "chen jinnan");
	set("title", "��ػ��ܶ���");
	set("nickname", "Ӣ���޵�");
	set("long", 
		"����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");

	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 30000);
	set("max_mp", 10000);
	set("mp", 10000);
	set("mp_factor", 100);
	set("combat_exp", 50000000);
	set("score", 500000);
	
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 200);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("wuhu_duanmendao", 200);
	set_skill("yunlong_jian", 200);
	set_skill("yunlong_shenfa", 200);
	set_skill("yunlong_bian", 200);
	set_skill("yunlong_shou", 200);
	set_skill("yunlong_zhua", 200);
	
	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu_duanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("book_count", 1);

	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���","ֻҪ������ػᣬ�������λ����ѧ���ա�");
	set_inquiry("���帴��","ȥ�ײĵ�ͻش�����ϸ���ưɣ�");
	set_inquiry("����","�����£�");
	set_inquiry("�п�","�����£�");
	set_inquiry("��������",ask_weiwang);
	set_inquiry("��������",ask_me);
	set_inquiry("�˻�",ask_tuihui);

	set("env/wimpy", 60);
	set("chat_chance_combat", 50);  
	setup();
	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
	carry_object("heilongbian");
	carry_object("gangdao");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	
	add_money(3000);
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * weapon;
	
	switch(random(8))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("sword xian", 1);
		break;
	case 2:
		perform_action("whip chan", 1);
		break;
	case 3:
	case 4:
		weapon = PresentName("changjian", IS_ITEM);
		if(query_weapon() == weapon && weapon)
			command(snprintf(msg, 40, "unwield %ld", weapon->object_id()));
		weapon=PresentName("heilongbian", IS_ITEM);
		if(query_weapon() == weapon && weapon)
			command(snprintf(msg, 40, "wield %ld", weapon->object_id()));
		else
			carry_object("heilongbian")->wield();
		perform_action("whip chan", 1);
		break;
	case 5:
	case 6:
		weapon = PresentName("heilongbian", IS_ITEM);
		if(query_weapon() == weapon && weapon)
			command(snprintf(msg, 40, "unwield %ld", weapon->object_id()));
		weapon=PresentName("changjian", IS_ITEM);
		if(query_weapon() == weapon && weapon)
			command(snprintf(msg, 40, "wield %ld", weapon->object_id()));
		else
			carry_object("changjian")->wield();
		perform_action("sword xian", 1);
		break;
	case 7:
	case 8:
		perform_action("force recover", 0);
		break;
	}
	
	return 0;
}

static char * ask_me(CNpc * npc , CChar * player)
{
	static char msg[255];

	if(DIFFERSTR(player->querystr("family/family_name"), "������"))
		return snprintf(msg,255,"%s�뱾��������������֪�˻��Ӻ�̸��",player->name());

	if (npc->query("book_count") < 1)
		return "�������ˣ����ɵ������澭���ڴ˴���";

	npc->add("book_count", -1);
	CContainer * ob = load_item("yljianpu");
	ob->move(player);
	return "�ðɣ��Ȿ���������ס����û�ȥ�ú����С�";
}

void init(CChar * me)
{
	CNpc::init(me);
/*	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
*/
}

virtual void attempt_apprentice(CChar * ob)
{
	if (ob->query_skill("yunlong-shengong", 1) < 50)
	{
		command("say �����������ڼ��书���������ڹ��ķ���"); 
		command("say ���Ƿ�Ӧ�����������϶��µ㹦��"); 
		return;
	}
	if (ob->query("����") <60)
	{
		command("say ���������书�����޵У��������ţ�\n�ش����������������壬Ϊ���²���ı������"); 
		command("say ���Ƿ�Ӧ���ȳ�ȥ��һ�������������춯�صĴ��£�"); 
		return;
	}
	if (ob->query("repute") >0&&(int)ob->query("repute") < 5000)
	{
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("�ڵ��з��棬���Ƿ����ò�����");
		return ;
	}
	if(ob->query("����")<80)
	{
		if(ob->query("repute")<0)
			command("say ����Ȼ��а�����ˣ���Ҳ������Щ���¡�\n");
		command("chat ����ػ�������Ϊ����һ����ǰ����δ��֮�¡�\n");
		command("chat ���¿������ң��������ţ������Ȼ���ֺ����ۣ�\n");
		command("chat �����������ɣ���\n");
		command("chat �벻����һ������ҵ�������������˴��ˣ�����������������\n");
		message_vision("$HIC$N�Ľ�����������ˣ�\n",ob);
		ob->set("����",80);
	}

	if(DIFFERSTR(ob->querystr("class"), "fighter"))
		ob->set("class","fighter");
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	static char msg[255];
	npc->say(snprintf(msg,255,"�����ڵĽ��������� %d ��",player->query("����")), player);
	npc->say("�½���˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�ꡣ��������\n", player);
	npc->SendMenu(player);
	return "";
}

static char * ask_tuihui(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "��ػ�"))
	{
		npc->say("�½���Ц��Ц������˵�����㻹û��������ػ��أ���ʲô�ˣ�", player);
		npc->SendMenu(player);
		return "";
	}
	if(EQUALSTR(player->querystr("family/family_name"), "������"))
	{
		npc->say("�½��ϰ���������˵�������Ѿ����������ŵ��ӣ�������˻᣿", player);
		npc->SendMenu(player);
		return "";
	}
	npc->command("sigh ");
	npc->command("say ���帴������Ҫ����־ʿ����ȥ��! ");
	player->del("party");
	return "";
}                                           
                                        

NPC_END;
