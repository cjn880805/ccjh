// quanzhen_zhangjing.c �ƾ�����

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangjing);

virtual void create()
{
	set_name("�ƾ�����", "zhangjing");
	set("gender", "����");
	set("age", 36);
	set("class", "taoist");
	set("long","��λ��ȫ������ƹܾ���ĵ���������ǰ�ǳ�������һ��˽�ӵķ��ӣ���Ϊ��Ľ������Űݵ���ȫ�����¡������Ͼ���Ϊ������ˣ�����ĸ������ò��Σ���Ҳ�������⣬���԰������ĵ��ж������ˡ�");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);
	set("icon",taoist_with_sword);
			set("foolid",44);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 900);
	set("max_mp", 900);
	set("mp_factor", 0l);
	
	set("combat_exp", 20000);
	set("score", 15000);
	
	set_skill("force", 40);
	set_skill("xiantian_qigong", 40);    //��������
	set_skill("sword", 40);
	set_skill("quanzhen_jian",40);  //ȫ�潣
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 40);   //���㹦
	set_skill("parry", 50);
	set_skill("unarmed",50);
	set_skill("strike",50);
	set_skill("haotian_zhang", 50);    //�����
	set_skill("literate",100);
	set_skill("taoism",80);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 4, "����");
	
	set("book_count",1);
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	set_inquiry("���¾�",ask_me);
	set_inquiry("һ��ָ",ask_zhipu);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" �ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static  char * ask_me(CNpc *who ,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "ȫ���"))
		return snprintf(msg,255,"%s�뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�",query_respect(me) );
	if (who->query("book_count") < 1)
		return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";
	who->add("book_count", -1);
	obj = load_item("daodejing_i");//���¾����Ͼ�
	obj->move(me);
	return "�ðɣ��Ȿ�����¾������û�ȥ�ú��ж����п������ĵط������ҡ�";
	
}

static  char * ask_zhipu(CNpc *me ,CChar *who)
{
	if(who->query_temp("tmark/ָ")==2) 
	{
		who->add_temp("tmark/ָ",1);
		return "һ��ָ��ָ�������������ɱ�����ʦ�����մ棬�Ӳ��⴫��";
	}
	else 
	{
		who->set_temp("tmark/ָ",0l);
		return "��˵һ��ָ��������������ָ������Ҳû�м�����";
	}
	return "";
}

NPC_END;