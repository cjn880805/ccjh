// quanzhen_zhangli.c �������

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangli);

virtual void create()
{
	set_name("�������", "zhangli");
	set("gender", "����");
	set("age", 22);
	set("class", "taoist");
	set("long","����һλ��ͺ���ĵ��ˣ��������ܸɣ���ȫ��̵��Ĵ������г���δ�����ǰ�������Ƿ�����������ȫ�����µ�����");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	set("icon",taoist);
			set("foolid",45);
	set("hp", 600);
	set("max_hp", 1800);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 0l);
	
	set("combat_exp", 30000);
	set("score", 20000);
	
	set_skill("force", 60);
	set_skill("xiantian_qigong", 50);    //��������
	set_skill("sword", 60);
	set_skill("quanzhen_jian",60);  //ȫ�潣
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //���㹦
	set_skill("parry", 60);
	set_skill("unarmed",60);
	set_skill("strike",60);
	set_skill("haotian_zhang", 50);    //�����
	set_skill("literate",50);
	set_skill("taoism",40);
	
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
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" �ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc *who ,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!( me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "ȫ���"))
		return snprintf(msg,255, "%s�뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�",query_respect(me) );
	if (who->query("book_count") < 1)
		return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";
	who->add("book_count", -1);
	obj = load_item("daodejing_ii");//���¾����¾�
	obj->move(me);
	return "�ðɣ��Ȿ�����¾������û�ȥ�ú��ж���";
	
}

NPC_END;