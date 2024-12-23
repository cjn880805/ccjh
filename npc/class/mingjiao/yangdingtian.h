//yangdingtian.������
//Lanwood 2001-3-21

NPC_BEGIN(CNmingjiao_yangdingtian);

virtual void create()
{
	set_name("������",  "yang lidi");
	set("long", "ֻ������������һ��С��֮�У�����ִ��һ����Ƥ�����������Ѫ����Ȼ���������࣬������������֮ɫһ�Լ����������ֱ��Ѫ��֮ɫ��������졣");
    set("title","���̵���ʮ��������");
	set("gender", "����");
    set("age", 40);
	set("shen_type",1);
    set("attitude", "friendly");
	set("icon",young_man2);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 10000);
    set("max_hp", 18000);
    
    set("mp", 6000);
    set("max_mp", 6000);
    set("mp_factor", 120);

	set("no_kill",1);//���ڱ�������������г���

    set("combat_exp", 8000000);
    set("score", 455000);
    
    set_skill("force", 280);
    set_skill("dodge", 28);
    set_skill("parry", 280);
	set_skill("unarmed", 280);
    set_skill("finger", 280);
	set_skill("xuantian_shengong", 280);
	set_skill("qiankun_danuoyi", 300);
	set_skill("xuantian_zhi", 300);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "xuantian_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("finger", "xuantian_zhi");
	prepare_skill("finger", "xuantian_zhi");

    create_family("����",33, "����");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
	set_inquiry("�뿪����", ask_leave);
	set_inquiry("Ǭ����Ų��", ask_qiankun);

    carry_object("baipao")->wear();
};

static char * ask_leave(CNpc *who,CChar *me)
{
	who->say("ȥ��������λ�Ѿ�ʯ�ƿ������������Ψһ���ڡ�", me);
	who->AddMenuItem("��ȥ�ƾ�ʯ", "$0leave $1",me);
	who->AddMenuItem("����", "", me);
	who->SendMenu(me);
	return 0;
}


static char * ask_qiankun(CNpc * npc , CChar * player)
{
	CContainer * ob;
	CContainer * r = load_room("���̹㳡");
	static char msg[255];
	
	if(DIFFERSTR(player->querystr("family/family_name"), "����"))
		return snprintf(msg,255,"%s�뱾�ɺ��޹ϸ𣬺��������ɵ����ܣ�",player->name());

	if (r->query_temp("no_book"))
		return "�������ˣ���Ƥ���Ѿ������ˡ�";

	r->add_temp("no_book",1);
	ob = load_item("qiankun_xinfa");
	ob->move(player);
	return "�ðɣ�������Ƥ���û�ȥ�úò������ɡ�";
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "leave") == 0)
	{
		return do_leave(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_leave(CChar * me)
{
	if(me->query_skill("qiankun_danuoyi", 1) < 80)
	{
		message_vision ("$Nʹ�����̵�����������ȥ����ϧ$N��Ǭ����Ų�ƹ������㣬��ǰ�ľ�ʯ��˿������", me);
		return 0;
	}
	else
	{
		message_vision ("$N����Ǭ����Ų���ķ������ɺ�����������죬�������ɵؾͰѾ�ʯ�ƿ������˳�ȥ��", me);

		CRoom * r = load_room("���̹㳡");
		me->move(r);	
		return 0;
	}
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("force heal", 0);
		break;
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("force roar", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"), "����"))
	{
		say("���Ѿ������������ɣ���ذɡ�", me);
		SendMenu(me);
		return;
	}

	if(DIFFERSTR(me->querystr("party/party_name"), "����"))//���Ĳ���
	{
		say("�����뱾��������������ذɡ�", me);
		SendMenu(me);
		return;
	}

	if(me->query_int() < 40)
	{
		say("�������̫���ˣ����ʺ�ѧϰ�ҵĹ���", me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("force", 1) < 150)
	{
		say("��Ļ����ڹ�̫���ˣ�ѧϰ�ҵĹ�����˼�����", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") <= 50000)
	{
		say("��Ӧ������Щ����������£��������ġ�", me);
		SendMenu(me);
		return;
	}

	if(me->query("party/level") < 5)
	{
		say("�����ʱ���ж̣��������������������������ͬ�⣬�һῼ��������ġ�", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
        
	me->set("party/level", 5);
	me->set("title", "�����״�����");
	say("�ã��Ҿ���������λ���ֵ�", me);
	say("�ٽ����£�", me);
	SendMenu(me);
	return;
}

NPC_END;




