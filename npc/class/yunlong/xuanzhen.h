//xuanzhen.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNyunlong_xuanzhen);

virtual void create()
{
	   set_name("��������", "xuan zhen");
	set("gender", "����");
	set("long", "��λ��Ĭ���Եĵ��ˣ�������ػ���ľ�û�����������ľ����һ�����ĺ��֣�һ������ʹ�ó����뻯��");
	set("age", 55);
	set("icon",old_man2);

	set("int", 30);
	
	set("hp", 1500);
	set("max_hp", 4500);
	set("shen_type", 1);

	set("combat_exp", 200000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("whip", 80);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong_shengong", 70);
	set_skill("yunlong_shenfa", 70);
	set_skill("yunlong_xinfa", 70);
	set_skill("yunlong_bian", 70);
	set_skill("yunlong_jian", 80);
	set_skill("yunlong_shou", 50);
	set_skill("yunlong_zhua", 50);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 60);

	map_skill("force", "yunlong_shengong");
	map_skill("dodge", "yunlong_shenfa");
	map_skill("parry", "yunlong_jian");
	map_skill("sword", "yunlong_jian");
	map_skill("hand", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand", "yunlong_shou");
	prepare_skill("claw", "yunlong_zhua");
	create_family("������",2, "����");
	set("class", "yunlong_xinfa");
	set("book_count", 1);

    set_inquiry("��Զ��","��������ֵ�ﵽ70�Ϳ��԰��ܶ���Ϊʦ��");
	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�");
	set_inquiry("���","ֻҪ��������ػᣬ��������и�λ����ѧ�书��");
    set_inquiry("���帴��","ȥҩ�̺͹ײĵ���ϸ���ưɣ�");
    set_inquiry("����",ask_weiwang);
	set_inquiry("������",ask_me);

	set("chat_chance_combat", 50);  

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	carry_object("changbian");
    add_money(3000);
}


virtual char * chat_msg_combat()
{
	static char msg[255];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * changbian = PresentName("changbian", IS_ITEM);

	switch(random(28))
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
		return "��������˵����������ԩ�޳𣬺α����?";
		
	}

	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

    npc->say(snprintf(msg,255,"%s�����ڵĽ�������Ҳ���� %ld", query_respect(player),player->query("weiwang")),player);
	npc->say("����˵����������ڽ����ϼ���һֻ�����ƵĹ���ǧ��Ҫ�۸���",player);
	npc->say("��Ҳ������������",player);
	npc->say("������˵����ϣ���ټ���������������س������Ļ�����",player);
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

        return "�ðɣ��Ȿ�������������û�ȥ�ú����С�";
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("weiwang") < 50)
	{
		say("���������书�������Ե���Ҫ��Ҳ�Ǽ��ߡ�",player);
		say("�������ȼ�������ػᣬ�����ҿ��Կ�������Ϊͽ��",player);
		SendMenu(player);
		return;
	}

	say("�ðɣ���Ȼ��Ҳ���ұ����ˣ������������ɡ�",player);
	SendMenu(player);
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
	
	if(DIFFERSTR(player->querystr("class"), "fighter"))
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

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if(ob->query("weiwang")>=50)
	switch( random(3)){
		case 1:
			say( "����Ц������λ" + RANK_D->query_respect(ob)
				+ "���Ҵ���ȥ���ðɡ�\n");
			ob->move("/d/city2/dating");
			message_vision("$N�����˴�����\n",ob);
			break;
		default:
			say( "����˵������λ" + RANK_D->query_respect(ob)
				+ "�����Ա㡣\n");
			break;
	}
	else say( "����Ц������λ" + RANK_D->query_respect(ob)
				+ "�����������ʲô��\n");
 
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