//beixiaofeng.h
//wq 2002-07-06

NPC_BEGIN(CNlj_beixiaofeng);

virtual void create()
{
	set_name("����", "xiao feng");
	set("gender", "����");
	set("age", 35);
	set("long", 
		"��������Ŀ������Ƶġ�������ǿ�ΰ����ʮ������ͣ�����ɫ�ɲ��ۣ���΢�����ã�Ũü���ۣ��߱����ڣ�һ���ķ��Ĺ����������з�˪֮ɫ������֮�ʣ��������ơ�");
	set("attitude", "peaceful");
	set("icon",begger);
	set("title","ؤ��");

	set("beggarlvl", 9);
	
	set("str", 55);
	set("int", 45);
	set("con", 53);
	set("dex", 44);
	set("per",24);

	set("chat_chance_combat", 30);
	
	set("hp", 25000);
	set("max_hp", 25000);
	set("mp", 14000);
	set("max_mp", 14000);
	set("mp_factor", 100);
	
	set("combat_exp", 2000000);
	set("score", 400000);
	 
	set_skill("force", 300);             
	set_skill("huntian_qigong", 300);    
	set_skill("unarmed", 300);           
	set_skill("xianglong_zhang", 300);   
	set_skill("dodge", 300);      	     
	set_skill("xiaoyaoyou", 300);        
	set_skill("parry", 300);             
	set_skill("staff", 300);             
	set_skill("dagou_bang", 300);        
	set_skill("begging", 300);          
	set_skill("xunshou_shu", 180);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	map_skill("staff", "dagou_bang");
	
	carry_object("yuzhu_zhang")->wield();
	set("no_kill",1);
	
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("staff zhuang", 1);
		break;
	case 1:
		perform_action("unarmed xianglong", 1);
		break;
	case 2:
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
