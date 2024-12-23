//yan.h
//Lanwood 2001-03-11

NPC_BEGIN(CNwudang_yan);

virtual void create()
{
	set_name("�����",  "yu daiyan");
	set("nickname", "�䵱����");
	set("long", "����һ���ɸɾ������಼��������������ʮ��ͷ��ͣ�˫�Ȳзϣ������������������佣��");
	set("gender", "����");
	set("age", 31);
	set("foolid",131);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 6000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50);
	
	set("combat_exp", 250000);
	set("score", 60000);
	
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 100);
	set_skill("taiji_quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set("chat_chance", 1);
	
	create_family("�䵱��", 2, "����");
	
	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

virtual char * chat_msg()
{
	if(random(2))
		return "���˵�������佣���Ƕ�ʦ����Ѫ��";
            
	return "�������̾������λ��ʦ���κ��ҵ��ȣ���Ҳ��Ѽׯһ�١�";
}
        

virtual void init(CChar * player)
{
	CNpc::init(player);
	if(userp(player) && !is_fighting())
	{
		if(DIFFERSTR(environment()->querystr("base_name"), "�䵱���ҹ���̨"))
			return;

		remove_call_out(do_greeting);
		call_out(do_greeting, 2, player->object_id());
	}
}

static void do_greeting(CContainer * ob , LONG param1 ,  LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target) return;

	if(! target->query_skill("taiji_shengong", 1))
    {
		message_vision("$CYNʮ�����Ӷ�$N�����ȵ��������аħ������������佣��\n\n", target);

		if(target->query("hp") < 500)
			target->unconcious();
		else
			target->receive_wound("hp", target->query("max_hp") / 2);
	//	if (target->query_combat_exp() < 2000)
	//	{
	//		target->set("combat_exp", target->query("sk_exp"));
	//		target->set("level", 1);
	//	}
      //  else 
	//		target->add("combat_exp", -1000);

		message_vision("$CYN���佣���ʱ��������̨�Ͻ����ݺᣬ��$NΧ�����롣\nʮ���ڳ����������$N���ϻ�����ʮ�������ӣ���Ѫ���졣\n\n\n$n����ŭ�ݣ���аħ�����Ҳ�Ҵ����佣�󣡡�\n$COM$n�Ӹ����£�����һ�ư�$N�����̨��\n\n\n", target, me);
		target->move(load_room("�䵱���ҹ�"));
		//g_Channel.do_channel(me, 0, "chat", snprintf(msg, 255, "%s˽�����佣������ɳ����ף�����һ����", target->name(1)));
   }
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (player->query_skill("taiji_shengong",1) < 30 )
	{
		say("���䵱����ע���ڹ��ķ������Ƿ�Ӧ����̫�����϶��µ㹦��",player);
		SendMenu(player);
		return;
	}
	
	if (player->query("repute") < 1000)
	{
		say("���䵱���������������ɣ��Ե���Ҫ���ϡ�",player);
		say("�ڵ��з��棬���Ƿ�Ӧ�ü�ǿһ�£�", player);
		SendMenu(player);
		return;
	}

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );	
}


NPC_END;