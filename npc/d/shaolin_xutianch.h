// shaolin_xutianch.c �캣��

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNshaolin_xutianch);

virtual void create()
{
	set_name("�캣��", "xu tianchuan");
	set("title",  "��ػ���ľ�û���");
	set("nickname", "�˱�Գ��");
	set("gender", "����");
	set("long", "������ľ����һ�����ĺ��֣����Ϲ���ʮ���˵ã�������ʹһ�׺�ȭ��");
	set("age", 55);
	
	set("int", 30);
    	set("icon",old_man1);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("shen_type", 1);
	
	set("combat_exp", 75000);
	set("attitude", "friendly");
	
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("unarmed", 90);
	set_skill("hand", 100);
	set_skill("hunyuan_yiqi", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("houquan", 100);
	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("env/wimpy", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "houquan");
	map_skill("unarmed", "houquan");
	map_skill("parry", "houquan");
	
	set("chat_chance", 3);
	
	set_inquiry("��Զ��","����ܶ����ɲ����װ���");
	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػᡣ");
	set_inquiry("���","ֻҪ��������ػᣬ��������и�λ����ѧ�书��");
	set_inquiry("ȥ�帴����","ȥҩ����������ϸ���ưɣ�");
	set_inquiry("����","�����£�");
	set_inquiry("��������",ask_weiwang);
	
	carry_object("cloth")->wear();
	add_money( 5000);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "�캣�������룬˵��������Ҫ�����ʹ����ҵ�������Ӳźð���";
	case 1:
		return "�캣��˵��: ������������Ҫ������ֵ�ߴ��кô�����";
	case 2:
		return "�캣��ͻȻ˵���Դ˴������ֵܣ�����������Բʱ��";
	case 3:
		return "�캣��ͻȻ˵���������Ž����֣��������ı����ġ�";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	CNpc::init(me);
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}
*/
static char * ask_weiwang(CNpc *who,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"�����ڵĽ��������� %ld" , me->query("weiwang") ), me);
	who->say("���������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦���������㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������", me);
	who->say("ɱĳЩ���˻��ĳЩ���˿�����߽���������", me);
	who->SendMenu(me);

	return "";
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"skills") == 0)
		return do_skills(me);
	return 0;
}

int do_skills(CChar * ob)
{
	if(wizardp(ob))  return 0;
	if (DIFFERSTR(ob->querystr("party/party_name"), "��ػ�")  )
	{
		message_vision("$Nҡ��ҡͷ��",this);
		tell_object(ob,"�캣��ŭ��������ػ���Ӳ��ܲ쿴������һ�٣�����Ц��:��Ȼ����ʦ���⡣");
		return 1;
	}
	
	//command(snprintf(msg,255,"tell %ld �����е��书���£������ڹ� (force) - 70\n�����Ṧ (dodge) - �����뻯  70    �����м� (parry) - һ����ʦ  90    ����ȭ�� (unarmed) - һ����ʦ  90    �����ַ� (hand) - ��ɲ� 100  ����Ԫһ���� (hunyuan_yiqi) - �����뻯  70  �������� (shaolin_shenfa) - �����뻯  70  ����ȭ (houquan) - ��ɲ� 100 ",ob->object_id() ) );
	return 1;
}

virtual int recognize_apprentice(CChar * ob)
{
    if (ob->query("weiwang")<50) return 0;

    return 1;
}


NPC_END;