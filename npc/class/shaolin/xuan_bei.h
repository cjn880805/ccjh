//xuan_bei.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xuan_bei);

virtual void create()
{
	set_name("������ʦ", "xuanbei dashi");
	set("long",	"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ���������ߣ���������񣬶��Ÿ��ʣ�˫ĿտȻ����");

	set("title", "���ִ�ĦԺ����");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",103);
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);

	set("combat_exp", 800000);
	set("score", 1000000);

//before the modification, all the skills are 150
	set_skill("force", 150);
	set_skill("hunyuan_yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin_shenfa", 150);
	set_skill("hand", 180);
	set_skill("claw", 180);
	set_skill("blade", 150);
	set_skill("sword", 150);
	set_skill("parry", 150);
	set_skill("qianye_shou", 175);
	set_skill("longzhua_gong", 175);
	set_skill("cibei_dao", 150);
	set_skill("damo_jian", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "qianye_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("blade", "cibei_dao");
	map_skill("sword", "damo_jian");
	map_skill("parry", "cibei_dao");

	prepare_skill("hand", "qianye_shou");
	prepare_skill("claw", "longzhua_gong");

	create_family("������", 36, "����");

	set("chat_chance_combat", 45);
	
	carry_object("jiasha")->wear();
	carry_object("changjian")->wield();
};

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword sanjue", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
	{
		say("���뱾��������������֪�˻��Ӻ�̸��", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "������")) 
	{
		say("�����׼ҵ��ӣ�����������ѧ�ա�", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("�⣬ƶɮ����ҵ� !", me);
		SendMenu(me);
		return;
	}

	char prename[3];
	strncpy(prename, me->name(), 2)[2] = 0;
	if ( (me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "��") == 0)
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", "���ִ�ĦԺ����"); 
		me->UpdateMe();
	}
	else
	{
		say("�㱲�ݲ��ϣ�����Խ����ʦ��", me);
		SendMenu(me);
		return;
	}

	return;
}

NPC_END;
