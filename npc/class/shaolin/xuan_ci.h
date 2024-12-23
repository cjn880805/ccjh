//xuan_ci.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xuan_ci);

virtual void create()
{
	set_name("���ʹ�ʦ", "xuanci dashi");
	set("long",	"����һλ�����ü����ɮ����һϮ��˿������ġ�������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣");
	
	set("title", "���������ַ���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",104);
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
	set("combat_exp", 3000000);
	set("score", 800000);

    set_skill("force", 250);
	set_skill("hunyuan_yiqi", 180);
	set_skill("dodge", 150);
	set_skill("shaolin_shenfa", 180);
	set_skill("finger", 190);
	set_skill("strike", 180);
	set_skill("hand", 110);
	set_skill("claw", 200);
	set_skill("parry", 200);
	set_skill("nianhua_zhi", 200);
	set_skill("sanhua_zhang", 200);
	set_skill("fengyun_shou", 200);
	set_skill("longzhua_gong", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 250);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("strike", "sanhua_zhang");
	map_skill("hand", "fengyun_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "nianhua_zhi");

	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");

	create_family("������", 36, "����");

	set("chat_chance_combat", 45);
	set_inquiry("����", ask_me);

    carry_object("jiasha")->wear();
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("finger fuxue", 1);
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
	if (DIFFERSTR(me->querystr("family/family_name"), "������"))
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

	strncpy(prename, me->name(1), 2)[2] = 0;

	if ( (me->query("family/generation") == query("family/generation") + 1)
		&& strcmp(prename, "��") == 0)
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", "���������״�����");
		me->UpdateMe();
	}
	else
	{
		say("�㱲�ݲ��ϣ�����Խ����ʦ��", me);
		SendMenu(me);
	}
}

static char * ask_me(CNpc * npc, CChar * me)
{
	//if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
    if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		npc->say("�����ӷ𣡳����˲���ڿ������׼��ˣ�����ʴ˻���֮�£�", me);
		npc->SendMenu(me);
		return 0;
	}
/*
	if ( DIFFERSTR(me->querystr("family/family_name"), "������")) 
	{
		npc->say("�����ӷ��㲻�����µ��ӣ�����֪�����λ����أ�", me);
		npc->SendMenu(me);
		return 0;
	}
*/	
	npc->say(g_Channel.do_emote(npc, 0, "sigh", 1), me); 
    me->set_temp("pending/huansu", 1); 
    npc->say("���Ȼ�����뿪����Ҳ��ǿ��", me);
    npc->say("������������������س��¶����봳ľ������Ը��?", me);
	npc->AddMenuItem("��Ը��", "$0decide $1", me);
	npc->AddMenuItem("��������", "", me);
	npc->SendMenu(me);
		
    return 0; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "decide") == 0 && me->query_temp("pending/huansu"))
	{
		me->delete_temp("pending_huansu");
		return do_decide(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_decide(CChar * me)
{
	load_item("lingpai")->move(me);
	me->say("���������Ѿ���", this);
	me->set_temp("teapot/passtest",1);
    say("�ðɣ���������������ס���ˣ��������ס�����Ժ�Ҫ�������£�������ɱ�޹������ҵ����ƴ�ľ����ȥ��!", me);
    SendMenu(me);
	
    return 1;        
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "�����·�����" ))
		return notify_fail("�����������");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
NPC_END;




