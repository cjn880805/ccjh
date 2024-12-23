//linhugongzi.h
//wq 2002-07-19

NPC_BEGIN(CNlj_linhugongzi);

virtual void create()
{
	set_name("�������", "lin hu");
	set("long", "������ݳ�,�����ʣ�����������������������ӡ�");
	set("gender", "����");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	set("per",33);

	set("title","��ɽ");
	
	set("hp", 15400);
	set("max_hp", 15400);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 60);
	
	set("combat_exp", 2000000);
	set("score", 100000);
	
	set_skill("unarmed",280);
	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("huashan_sword", 280);

	set_skill("huashan_shenfa", 280);
	set_skill("feiyan_huixiang",280);
	set_skill("lonely_sword",280);
	set_skill("literate", 280);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	
//	create_family("��ɽ��", 14, "����");
	
	carry_object("changjian")->wield();
	set("chat_chance_combat", 10);
	set("no_kill",1);
}

	
virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword poqi", 1);
		break;
	case 1:
		perform_action("force recover", 0);
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
