//nanmonong.h
//wq 2002-07-6

NPC_BEGIN(CNlj_nanmonong);

virtual void create()
{
	set_name("Ľ��", "mu rong");
	set("long","�����������ٷ磬�������Ρ�ֻ��˫����ż����¶�����׹����˲���������");
	set("age", 27);

	set("title","����");
	set("attitude", "friendly");
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",young_man2);
	
	set("per",33);
	
	set("hp", 25000);
	set("max_hp", 25000);
	set("mp", 14500);
	set("max_mp", 14500);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 50000);
	
	set_skill("xingyi_zhang",300);
	set_skill("strike",300);
	set_skill("finger",300);
	set_skill("dodge",300);
	set_skill("force", 300);
	set_skill("canhe_zhi", 300);
	set_skill("murong_jianfa",300);
	set_skill("shenyuan_gong", 300);
	set_skill("yanling_shenfa", 300);
	set_skill("douzhuan_xingyi", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("literate", 300);
	set_skill("murong_daofa", 300);
	set_skill("blade",300);
	
	map_skill("blade", "murong_daofa");
	map_skill("finger", "canhe_zhi");
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "douzhuan_xingyi");
	map_skill("sword", "murong_jianfa");
	
	prepare_skill("finger", "canhe_zhi");

	if(random(2))
		carry_object("sword_1")->wield();
	else
		carry_object("blade_1")->wield();
	set("no_kill",1);
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
		message_vision("\n$HIY$n̾������λ���֣�������$N�ܵ��ķ��ڷ����������л�Ե��������̣�����ˡ�",winner,failer);
		message_vision("$HIY$n˵�ն��ڳ����˹���һ����˾��̫���˳�����ȥ��",winner,failer);
		destruct(failer);
	}
	else if(userp(failer))
	{
		message_vision("\n$HIY$Nһ��ժ���Լ����ϵ���ߣ�ˤ�ڵ��¡�\nֻ��$N����ͨ�죬����������һ�㶼�����档�����飬�����飬Ҫ�����Ų����Լ����Ұ�����",failer);
		message_vision("$HIY$N˵�������˾����Ŀ���У�$n�ƿ�ǰ����·��̫�࣬����ֱ�ӳ�����",failer);
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