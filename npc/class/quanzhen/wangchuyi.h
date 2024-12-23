// quanzhen_wangchuyi.c ����һ

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_wangchuyi);

virtual void create()
{
	set_name("������","wang laowu");
	set("gender", "����");
	set("age", 35);
	set("class", "taoist");
	set("nickname","������");
	set("long","������ȫ������֮�������������ˡ�������޳����������࣬��縺���Ʈ����ǰ����̬������");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("foolid",55);	set("con", 32);
	set("dex", 30);
	set("icon",taoist);
	
	set("title","ȫ������֮��");
	set("chat_chance_combat", 60);
	set("chat_chance", 8);
	
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("xiantian_qigong", 220);    //��������
	set_skill("sword", 220);
	set_skill("quanzhen_jian",220);  //ȫ�潣
	set_skill("dodge", 200);
	set_skill("jinyan_gong", 200);   //���㹦
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("haotian_zhang", 220);    //�����
	set_skill("literate",160);
	set_skill("strike",180);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 2, "����");
	
	set("book_count",1);
	
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	set_inquiry("�ϵ�",ask_me);
	set_inquiry("�λ�ү",ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_huan",1);
}

virtual char *chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "����һ��̾һ���������ɺ������ٰ��ҵ�ҩȫ���������ˡ�";
	case 1:
		return "����һ����˭�ܰ����һ�ҩ������һ�����س�л����";
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("xiantian_qigong",1) < 80 )
	{
		say("��ı����ڹ��ķ������,�������Ը�������书��", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<30000) 
	{
		say("�����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��", ob);
		SendMenu(ob);
		return;
	}

	say("�ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (   DIFFERSTR(ob->querystr("name"), "�ܵ�")
		&& DIFFERSTR(ob->querystr("name"), "����")
		&& DIFFERSTR(ob->querystr("name"), "ûҩ")
		&& DIFFERSTR(ob->querystr("name"), "Ѫ��") )
		return 0;
	
	//	remove_call_out(destroying);
	//	call_out(destroying, 1, me, ob->object_id() );
	destruct(ob);
	say("��Ϊ���ˣ��ҿ��Խ���㹦��", who);
	SendMenu(who);
	
	who->add_temp("tmark/��", 10);
	//����who�Ĳ˵�
	DownLoad(who);
	return 1;
	
}

static char * ask_me(CNpc *who,CChar *me)
{	
	if(me->query_temp("tmark/ָ")==1) 
	{
		me->add_temp("tmark/ָ",1);
		return("ȥ��ʦ��ȥ���λ�ү�����˵�λ�ү������������һ��ָ�����ڸ���ʦ���ˡ�");
	}
	else 
	{
		me->set_temp("tmark/ָ",0l);
		return("�λ�ү������һ���������£����ڳ������˺����ˣ�����");
	}
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if ( EQUALSTR(me->querystr("family/family_name"), "ȫ���")) return 0;

	if (! me->querymap("family"))
	{
		say("��ɻ�û�ݹ�ʦ����Ҫѧ�������Ȱݸ�ʦ����˵�ɡ�");
		return 1;
	}

	if ( me->query_temp("tmark/��") == 1 )
	{
		me->delete_temp("tmark/��");
		DownLoad(me);

		say("���ܽ���Ķ�������Ϊֹ����Ҳ��Ҫ������ѧ�����ˡ�", me);
		SendMenu(me);
		return 1;
	}

	me->add_temp("tmark/��", -1);
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if (! me->query_temp("tmark/��"))
		return 0;

	return 1;
}

NPCQUANZHEN_END;