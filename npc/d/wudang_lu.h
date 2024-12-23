// wudang_lu.c ½����

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNwudang_lu);

virtual void create()
{
	set_name("½ɯ��", "lu feiqing");
	set("long","½ɯ�죬���䵱�ɴ�����׳��ʱ�ڴ��ϱ��������壬�˵����𽭺��� ");
	set("nickname", "������");
	set("gender", "����");
	set("class", "scholar");

	set("age", 62);
        set("icon",young_man5);
	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 23);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 9000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("taiji_quan", 150);
	set_skill("taiji_shengong", 200);
	set_skill("taiji_dao", 200);
	set_skill("taiji_jian", 200);
	set_skill("liangyi_jian", 150);
	set_skill("tiyunzong", 200);
	
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("unarmed", "taiji_quan");
	map_skill("blade", "taiji_dao");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "liangyi_jian");
	set("chat_chance_combat", 60);
	set("env/wimpy", 60);
	create_family("�䵱��", 17, "����");
	
	carry_object("greyrobe")->wear();
	carry_object("changjian")->wield();
}

/*       set("chat_msg_combat", ({
(: perform_action, "sword.ren" :),
(: exert_function, "powerup" :),
(: exert_function, "recover" :),
        }) );*/

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword ren", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}
/*
virtual void init(CChar * me)
{	
	CNpc::init(me);
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		me->delete_temp("apply");
		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N������ü��������˵��������ҪӰ���ҿ��羰����", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
*/
NPC_END;



