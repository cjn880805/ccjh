//ma.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNyunlong_ma);

virtual void create()
{
	   set_name("���˳�", "ma chaoxing");
	set("nickname", "����" );
	set("long","��");
	set("gender", "����");
	set("age", 21);
	set("icon",young_man4);
	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_force", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 150);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("wuhuduanmendao", 150);
	set_skill("yunlong_jian", 200);

	set_skill("yunlong_shenfa", 150);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 150);
	set_skill("yunlong_zhua", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("class", "yunlong_xinfa");
	set("book_count", 1);

    set_inquiry("��Զ��","n��������ֵ�ﵽ80�Ϳ��԰��ܶ���Ϊʦ��");
    set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�");
	set_inquiry("���","ֻҪ������ػᣬ�������λ����ѧ���ա�");
    set_inquiry("����","��Ҳ�������");
    set_inquiry("����","�����Թſ����");
    set_inquiry("����",ask_weiwang);
	set_inquiry("��������",ask_me);

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  

	carry_object("changbian")->wear();
	carry_object("changjian")->wield();
	carry_object("dadao")->wield();
	carry_object("cloth")->wield();
}


virtual char * chat_msg_combat()
{
	static char msg[255];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * changbian = PresentName("changbian", IS_ITEM);
	CContainer * dadao = PresentName("dadao", IS_ITEM);

	switch(random(33))
	{
	case 0:
		g_Channel.do_emote(this, 0, "smile", 0);
		break;
	case 1:
		g_Channel.do_emote(this, 0, "haha", 0);
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		if(query_weapon() == changjian && changjian)
			command(snprintf(msg, 40, "unwield %ld", changjian->object_id()));
		break;
	case 11:
		if(! query_weapon() && changjian)
			command(snprintf(msg, 40, "wield %ld", changjian->object_id()));
		break;
	
	case 12:
	case 13:
	case 14:
		perform_action("sword xian",1);
		break;
	case 15:
	case 16:
		perform_action("whip chan",1);
		break ;
	case 17:
	case 18:
		perform_action("force recover",0);
		break ;
	case 19:
	case 20:
	case 21:
	case 22:
		if(! query_weapon() && changbian)
			command(snprintf(msg, 40, "wield %ld", changbian->object_id()));
		break ;
	case 23:
	case 24:
	case 25:
	case 26:
		if(query_weapon() == changbian && changbian)
			command(snprintf(msg, 40, "unwield %ld", changbian->object_id()));
		break ;
	case 27:
		return "���˳�˵����������ԩ�޳𣬺α����?";

	case 28:
	case 29:
	case 30:
	case 31:
		if(query_weapon() == dadao && dadao)
			command(snprintf(msg, 40, "unwield %ld", dadao->object_id()));
		break;
	case 32:
		if(! query_weapon() && dadao)
			command(snprintf(msg, 40, "wield %ld", dadao->object_id()));
		break;
	}

	return 0;
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

    npc->say(snprintf(msg,255,"%s�����ڵĽ��������� %ld������Ҳ��֪���ǲ�����ô��", query_respect(player),player->query("weiwang")),player);
	npc->say("���˳�˵����������һֻ�����������ϵ�Ӣ�۶�����������",player);
	npc->say("������̫�����ˡ���",player);
	npc->say("���˳���˵��ǧ��Ҫѧ����",player);
	npc->SendMenu(player);
	return "";
}

static char * ask_me(CNpc * npc , CChar * player)
{
		CContainer * ob;

        if (DIFFERSTR(player->querystr("family/family_name"), "������"))
                return "���뱾��������������֪�˻��Ӻ�̸��";

        if (npc->query("book_count") < 1)
                return "�������ˣ����ɵ������澭���ڴ˴���";

        npc->add("book_count", -1);
        ob = load_item("yljing2");
        ob->move(player);

        return "�ðɣ��Ȿ���������ס����û�ȥ�ú����С�";
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if(EQUALSTR(player->querystr("gender"), "����"))
	{
 		say("�����Ŷ������أ��������������ķ��ˣ���",player);
 		SendMenu(player);
		return;
	}
	say("�ðɣ���Ȼ��Ҳ���ұ����ˣ������������ɡ�",player);

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );

	if( DIFFERSTR(player->querystr("class"), "fighter"))
		player->set("class","fighter");

}
/*
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "������$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;
    }
   else	return notify_fail("���Ѿ�������ػ��ˣ�\n"); 
}


*/


virtual int recognize_apprentice(CChar * player)
{
    if (player->query("weiwang")<50)
    {
		message_vision("$Nҡ��ҡͷ������̫���Ҳ��̡�",player);
		return 0;
    }
    return 1;
}



NPC_END;