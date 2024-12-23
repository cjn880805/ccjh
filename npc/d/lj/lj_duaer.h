//duaner.h
//wq 2002-07-19

NPC_BEGIN(CNlj_duaer);

virtual void create()
{
	set_name("����", "duan yu");
	set("long", "������ü��Ŀ�㣬�������İ���ʥ�֡�");
	set("gender", "����");
	set("icon", young_man4);
	
	set("title", "����");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 45);
	set("dex", 40);
	set("per",32);
	
	set("max_hp", 26000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 300000);
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("finger", 300);
	set_skill("kurong_changong", 300);
	set_skill("tiannan_step", 300);
	set_skill("jinyu_quan", 300);
	set_skill("wuluo_zhang", 300);
	set_skill("duanjia_sword", 300);
	set_skill("sun_finger", 300);
	set_skill("lm_shangyang", 300);
	set_skill("literate", 300);
	
	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "sun_finger");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "sun_finger");
	map_skill("sword", "duanjia_sword");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");
	
	carry_object("cloth")->wear();
	carry_object("sword_1")->wield();
	add_money(5000);
	set("no_kill",1);

};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("���ݻʹ�����");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu115") )
	{
		me->set_temp("lj/renwu115",1);
		me->disable_player("�ȴ���");
		call_out(do_start, 5);
	}
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * r = load_room("���ݻʹ�����");
	message_vision("\n$HIR������ȵĽ�����ʱ�򣬴����߳�һ���װ����ֵ�̫��,�����ߵ���ǰ��ϸ��ϸ����˵����", me);
	message_vision("$HIR�����λ���������鷿���ԣ���ĺ��������Ů����װ�����������ڴ˴���Ϣ����\n", me);
	message_vision("$HIR��ĺ�����ߡ���һ������ͷ�����ȥ��", me);
	message_vision("$HIR\n�㲻�ɵð������Ұ���������Ƥ���������ϸ����֮��������װ���ײ�����ˣ�\n", me);
	me->enable_player();
	if(!r->query("start"))
		r->set("start",1);

	DTItemList * list = r->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))
		{
			target->enable_player();
			continue;
		}
		if(DIFFERSTR(target->querystr("name"), "��ĺ��") && DIFFERSTR(target->querystr("name"), "����"))
			target->move(load_room("���ݻʹ�������"));
		else if(EQUALSTR(target->querystr("name"), "��ĺ��"))
			destruct(target);

	}
	me->move(load_room("���ݻʹ�������"));
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

