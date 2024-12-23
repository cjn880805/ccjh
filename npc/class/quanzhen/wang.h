//wang.c ������
//Lanwood
//2001-01-15

ZUSHI_BEGIN(CNquanzhen_wang);

virtual void create()
{
	set_name("������", "wang chongyang");
	set("gender", "����");
	set("age", 66);
	set("class", "taoist");
	set("nickname", "������");
	set("long","������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������ƮƮ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("foolid",33);
	set("chat_chance_combat", 60);
	
	set("hp", 29500);
	set("max_hp", 29500);
	
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_factor", 300);
	
	set("combat_exp", 70000000);
	set("score", 500000);
	
	set_skill("force", 280);
	set_skill("sword", 300);
	set_skill("dodge", 290);
	set_skill("parry", 280);
	set_skill("unarmed",290);
	set_skill("strike",280);
	set_skill("finger",400);
	set_skill("literate",180);
	set_skill("taoism",220);

	set_skill("xiantian_qigong", 260);
	set_skill("xiantian_gong", 280);
	set_skill("quanzhen_jianfa",300);  //ȫ�潣
	set_skill("quanzhen_jian",300);  //ȫ�潣
	set_skill("jinyan_gong", 240);   //���㹦
	set_skill("haotian_zhang", 240);    //�����
	set_skill("sun_finger",200);  //һ��ָ

	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jianfa");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jianfa");
	map_skill("strike", "haotian_zhang");
	map_skill("finger","sun_finger");

	prepare_skill("finger","sun_finger");
	prepare_skill("strike","haotian_zhang");
	
	create_family("ȫ���", 1, "�ƽ�");
	
	set("book_count",1);
	set_inquiry("ȫ���", "��ȫ��������µ����������ڡ�");
	set_inquiry("�����澭", ask_jiuyin);
	set_inquiry("һ��ָ", ask_zhipu);
	set_inquiry("�λ�ү", ask_duan);
	
	carry_object("changjian")->wield();
	carry_object("greenrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * changjian = present("changjian");

	switch(random(19))
	{
	case 0:
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
	case 3:
	case 4:
		perform_action("strike ju", 1);
		break;
	case 5:
	case 6:
	case 7:
		perform_action("sword ding", 1);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		if(query_weapon() == changjian && changjian)
			command(snprintf(msg, 40, "unwield %ld", changjian->object_id()));
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		if(! query_weapon() && changjian)
			command(snprintf(msg, 40, "wield %ld", changjian->object_id()));
		break;
	case 16:
	case 17:
	case 18:
		perform_action("finger qiankun", 1);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[40];
	
	if (me->query_int() < 30) 
	{
		say("������ʲ����������������Ǽ���ͽ��ѧϰ�ɡ�", me);
		SendMenu(me);
		return;
	}
	if ( me->query_skill("xiantian_qigong",1) < 150 ) 
	{
		say("��ı����ڹ��ķ������,�������Ը�������书��", me);
		SendMenu(me);
		return;
	}
	
	if (me->query("repute")<80000) 
	{
		say("�����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��");
		SendMenu(me);
		return;
	}
	
	say("�ðɣ��������ʣ����ɴ����²����Ҿ����������ͽ���ˡ�");
	command(snprintf(msg, 40, "recruit %ld", me->object_id()));
}

static char * ask_jiuyin(CNpc * npc, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "ȫ���"))
		return "���뱾�̺��޹ϸ��⻰�Ӻ�˵��";
	
	if(who->query_skill("force",1) < 50 )
		return "��Ļ����ڹ�������֮ǳ��ǿ���澭�ϵ��ϳ��书�к����档";
	
	return "�����澭��������ѧ���ڣ����ѽ�����ʦ���ܲ�ͨ���ܣ���";
}

static char * ask_duan(CNpc * npc, CChar * who)
{
	if(who->query_temp("tmark/ָ")==4) 
	{
		who->add_temp("tmark/ָ",1);
		return "�λ�ү�ųơ��ϵۡ����Ҵ���һ��ָ��������������ָ����";
	}
	
	who->set_temp("tmark/ָ",0l);
	return "���ʶλ�ү����ô��Ī��������Ϊ�ѣ�";
}

static char * ask_zhipu(CNpc * npc, CChar * who)
{
	if(who->query_temp("tmark/ָ")==5) 
	{
		who->set_temp("tmark/ָ",0l);
		if(npc->query("book_count") > 0) 
		{
			load_item("zhifapu")->move(who);
			npc->add("book_count",-1);
			return "�ðɣ���������࣬��־���ᣬ�Ȿָ���׾ͽ������ˡ�";
		}
		
		else
			return "�������ˣ�ָ�����Ѿ�����ȡ���ˡ�";
	}
	
	
	who->set_temp("tmark/ָ",0l);
	return  "�㲻������ҽ��������ɣ�";      
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "��������ɽ" ))
		return notify_fail("�����������");
	char msg[255];
	if( EQUALSTR(ob->querystr("base_name"), "cyjian")&& who->query_temp("gumu/cyjian"))
	{
		destruct(ob);
		command("sigh");
		CContainer * bot = load_item("xiangsijianpu");
		bot->set("owner1",who->id(1));
		bot->move(who);
		say("�����Ǵ�������������.....",who);
		say("�����ҽ������ʵ����������Ӣ��һƬ���顣��������",who);
		say("лл���ˣ�С�ֵܡ�",who);
		say("����������ĵ��������ҵ���÷�ؼ㣬����ȥ�ɣ�",who);
		say("����ǳ�Ӣ���ӣ�Ӧ������������⡣",who);
		who->delete_temp("gumu/cyjian");
		who->set_temp("gumu/read",1);
		SendMenu(who);
		return 1;
	}
	else if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
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

ZUSHI_END;




