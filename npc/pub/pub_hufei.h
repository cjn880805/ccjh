// pub_hufei.c 

// code by Fisho
// date:2000-12-17
//���NPC������д���ظ�
NPC_BEGIN(CNpub_hufei);

virtual void create()
{
	set_name("����","hu fei");

	set("icon", young_man2);
	set("gender", "����");
	set("nickname", "ѩɽ�ɺ�");
	set("age", 25);
	set("long","�����Ǻ���֮�ӣ������书��ǿ�����û���ڽ�����������š�ѩɽ�ɺ���������һ����ɫ�������������һ�ѿ������ܾɵĵ�����������ף�����������һͷŨ����ȴ����衣");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 20);
	
	set("hp", 3000);
	set("max_hp", 9000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // �����ڹ�
	set_skill("hujia_daofa", 150);    // ���ҵ���	
	set_skill("blade", 120);           // ��������
	set_skill("hunyuan_yiqi", 120);   // ��Ԫһ����
	set_skill("dodge", 120);           // ��������
	set_skill("shaolin_shenfa", 120);   // ������
	set_skill("parry", 120);             // �����м�
		
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
   	
	set_inquiry("����",ask_me);

	set("baodao_count",1);
	carry_object("cwbdao")->wield();
    carry_object("cloth")->wear();
 
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "����̾�˿�����:����֪ʲôʱ�����ټ�������";
	case 1:
		return "���ɺ޺޵���������������ɱ�����ˣ��ұر��˳𣡡�";
	}
	return "";
}

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer * obj;
	if( me->query("repute") < 0)
	{
		who->call_out(do_kill,1,me->object_id());
		return "";
	}

	if( me->query("repute") < 100000 )
	    return "����Ŀǰ����Ϊ�ǲ�������ѵ��ġ�";

   	if(me->query("baodao_count") > 1)
	{		
    //	call_out(waiting,0,me,ob->object_id());
		me->add("baodao_count", -1);
    	obj = load_item ("cwbdao");//��������
    	obj->move(me);
		return " �ðɣ���Ѵ��������������㣬ϣ����ú���������";
	}
	
	return "��������, ������ѵ��Ѳ��ڴ˴���";
}

static void do_kill(CContainer *ob,LONG param1,LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me=(CChar *)(npc->environment())->Present(param1);
	if (!me) return;
 
    if ((me->environment())->query("no_fight"))
	    (me->environment())->set("no_fight", 0l);
 
    if (userp(me))
    {
        npc->say("����������Ҵ��ұ���������, ������������");
		npc->kill_ob(me);
    }
}	

NPC_END;