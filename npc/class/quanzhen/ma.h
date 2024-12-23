// quanzhen_ma.c ����

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_ma);

virtual void create()
{
	set_name("����", "ma yu");
	set("gender", "����");
	set("age", 42);
	set("class", "taoist");
	set("nickname","������");
	set("long","�������������Ĵ���ӣ�ȫ������֮�ף����������������ˡ�����ü��Ŀ���Ͱ����ף���Ц�ſ����㡣");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 28);
	set("foolid",54);
	set("int", 32);
	set("con", 31);
	set("dex", 30);
	set("icon",taoist);
	
	set("title","ȫ������֮��");
	
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("sword", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 220);    //��������
	set_skill("quanzhen_jian",220);  //ȫ�潣
	set_skill("jinyan_gong", 200);   //���㹦
	set_skill("haotian_zhang", 220);    //�����

	set_skill("literate",160);
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
	set_inquiry("���㹦",ask_me);
	set_inquiry("����ͼ��",ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
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

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!( me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "ȫ���"))
		return  snprintf(msg,255,"%s�뱾�̺��޹ϸ��ҽ̵��书�伮�ɲ��ܽ����㡣",query_respect(me) );
	if (who->query("book_count") < 1)
		return "�������ˣ�����ͼ���Ѿ�����ȡ���ˡ�";
	who->add("book_count", -1);
	obj = load_item("jinyantu");//����ͼ��
	obj->move(me);
	return "�ðɣ��Ȿ������ͼ�ס����û�ȥ�ú��ж���";
	
}

NPCQUANZHEN_END;