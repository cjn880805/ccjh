//lj_zhoubotong 
//wq
//2002-07-19

NPC_BEGIN(CNlj_zhoubotong);

virtual void create()
{
	set_name("�ܲ�ͨ", "zhou botong");
	set("gender", "����");
	set("age", 26);
	
	set("title", "����");
	set("long","������ȫ��������˵�ʦ�ܣ��书��ǿ��ȴ�е��ͷ���Եġ�");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("foolid",33);

	set("per",18);
	
	set("hp", 19500);
	set("max_hp", 19500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	
	set("combat_exp", 20000000);
	set("score", 500000);
	
	set_skill("force", 280);
	set_skill("dodge", 290);
	set_skill("parry", 280);
	set_skill("unarmed",300);
	set_skill("kongming_quan",300);
	set_skill("jinyan_gong",300);
	set_skill("xiantian_qigong",300);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "kongming_quan");
	map_skill("unarmed", "kongming_quan");
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