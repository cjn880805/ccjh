// chen.c �½���

NPC_BEGIN(CNtdh_chen);

virtual void create()
{
	set_name("�½���", "chen jinnan");
	set("title", "��ػ��ܶ���");
	set("nickname", "Ӣ���޵�");
	set("long", "����һ����ʿ����������������ɫ�Ͱ���������������������ػ��ܶ����½��ϣ���˵ʮ�˰����գ�������ͨ��ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("per",27);
	
	set("max_hp", 13000);
	set("max_mp", 10000);
	set("hp", 13000);
	set("mp", 10000);
	set("combat_exp", 2000000);
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
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 200);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-bian", 200);
	set_skill("yunlong-shou", 200);
	set_skill("yunlong-zhua", 200);
	
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
	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
	carry_object("hlbian");
	carry_object("gangdao");

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


virtual void attempt_apprentice(CChar * ob)
{
	if (ob->query_skill("yunlong_shengong", 1) < 50)
	{
		message_vision("�����������ڼ��书���������ڹ��ķ���\n$N�Ƿ�Ӧ�����������϶��µ㹦��",ob);
		return;
	}
	if (ob->query("weiwang") <60)
	{
		message_vision("���������书�����޵У��������ţ�\n�ش����������������壬Ϊ���²���ı������\n$N�Ƿ�Ӧ���ȳ�ȥ��һ�������������춯�صĴ��£�",ob);
		return;
	}
	if (ob->query("repute") >0 &&ob->query("repute") < 5000)
	{
		message_vision("ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�\n�ڵ��з��棬$N�Ƿ����ò�����",ob);
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if(ob->query("repute")<0)
			message_vision("$N��Ȼ��а�����ˣ���Ҳ������Щ���¡�",ob);

		message_vision("\n����ػ�������Ϊ����һ����ǰ����δ��֮�¡�",ob);
		message_vision("���¿������ң��������ţ������Ȼ���ֺ����ۣ�",ob);
		message_vision("���������$N�ɣ���",ob);
		message_vision("�벻����һ������ҵ�������������˴��ˣ�����������������\n",ob);

		message_vision("$HIC$N�Ľ�����������ˣ�\n",ob);
		ob->set("weiwang",80);
	}
/*
	if(DIFFERSTR(ob->querystr("class"), "fighter"))
		ob->set("class","fighter");
*/
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	static char msg[255];
	npc->say(snprintf(msg,255,"�����ڵĽ��������� %d ��",player->query("weiwang")),player);
	npc->say("�½���˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n",player);
	npc->say("�½�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n",player);
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
