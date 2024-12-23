//zhangsanfeng.h
//wq
//2002-07-19
NPC_BEGIN(CNlj_zhangsanfeng);

virtual void create()
{
	set_name("������","zhang sanfeng");
	set("title", "����" );
	set("long", "����һ���ۻ���·������ޱ߷�����ĸߴ�ü��Ŀ�㣬˫�������â��");
	set("gender", "����");
	set("age", 18);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("per",34);

	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 100);
	set("combat_exp", 2000000);
	set("score", 1200000);

	set_skill("force", 280);
	set_skill("taiji_shengong", 280);
	set_skill("dodge", 280);
	set_skill("tiyunzong", 280);
	set_skill("unarmed", 280);
	set_skill("taiji_quan", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("taiji_jian", 280);
	set_skill("blade", 280);
	set_skill("taiji_dao", 280);
	set_skill("taoism", 280);
	set_skill("literate", 280);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

//	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	set("chat_chance_combat", 30);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_kill",1);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}


void is_defeated(CChar * winner, CChar * failer)
{

	//�����Ǳ����ʤ�ߵĴ���
	winner->add_temp("lj/biwu/win",1);
	winner->delete_temp("biwu");
	if(winner->query_temp("no_fei"))
		winner->delete_temp("no_fei");
	failer->delete_temp("biwu");
	if(failer->query_temp("no_fei"))
		failer->delete_temp("no_fei");

	winner->revive(1);
	failer->revive(1);
	winner->set("hp",winner->query("max_hp"));
	winner->set("eff_hp",winner->query("max_hp"));
	winner->set("mp",winner->query("max_mp"));
	message_vision("$HIY$N�������һ�ˣ�Ц����$n�֣������ˡ�",winner,failer);
	if(userp(winner))
	{
		message_vision("\n$HIY$n̾������λ���֣�������$n�ܵ��ķ��ڷ����������л�Ե��������̣�����ˡ�",winner,failer);
		message_vision("$HIY$n˵�ն��ڳ����˹���һ����˾��̫���˳�����ȥ��",winner,failer);
		destruct(failer);
	}
	else if(userp(failer))
	{
		message_vision("\n$HIY$Nһ��ժ���Լ����ϵ���ߣ�ˤ�ڵ��¡�\nֻ��$N����ͨ�죬����������һ�㶼�����档�����飬�����飬Ҫ�����Ų����Լ����Ұ�����",failer);
		message_vision("$HIY$N˵�������˾����Ŀ���У�$N�ƿ�ǰ����·��̫�࣬����ֱ�ӳ�����",failer);
		message_vision("$HIY��ָ��$N����Ӱ�����Ų�����ֻ����ԶԶ�Ĵ������������Ǿͼ��������ǵ�����ɣ���С����Ҳ���������ĵĺ����ˡ���",failer);

		message_vision("\n$HIR��ʧȥ�������ʸ�",failer); 
		message_vision("$HIR��μӱ�������ʧ�ܣ���Ե�������Ĺ��������޷���֤�ι��ڹ��ںδ�����֮̾��ֻ�з��� ��\n\n",failer); 
		failer->del("lj");
		failer->delete_temp("lj");
		failer->enable_player();
		CContainer * env = load_room("���ݻʹ�����");
		if(env->query("start"))env->del("start");
		env = load_room("���ݻʹ�����");
		if(env->query("start"))env->del("start");
		failer->move(load_room("���ݻʹ�����"));
	}
	else
	{
		message_vision("\n$HIY$n̾����$N�֣�������$n�ܵ��ķ��ڷ����������л�Ե��������̣�����ˡ�",winner,failer);
		destruct(failer);
	}
}

NPC_END;