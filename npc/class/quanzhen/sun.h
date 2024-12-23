//sun.c �ﲻ��
//Lanwood
//2001-01-15

NPCQUANZHEN_BEGIN(CNquanzhen_sun);

virtual void create()
{
	set_name("��˵һ", "sun suoyi");
	set("gender", "Ů��");
	set("age", 33);
	set("class", "taoist");
	set("nickname", "�徻ɢ��");
	set("long",  "������ȫ��̶���������Ψһ��Ů������˵һ�����ˡ��������������ǰ�����ӣ�����������һ������ͷ��");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("foolid",35);
	set("title","ȫ������֮ĩ");
	set("chat_chance_combat", 60);
	
	set("hp", 4000);
	set("max_hp", 12000);
	
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 180);
	set_skill("sword", 180);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("unarmed",180);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 200);    //��������
	set_skill("quanzhen_jian",200);  //ȫ�潣
	set_skill("jinyan_gong", 180);   //���㹦
	set_skill("haotian_zhang", 200);    //�����

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
	set_inquiry("ȫ���", "��ȫ��������µ����������ڡ�");
	set_inquiry("�����", ask_me);
	
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
	if (DIFFERSTR(ob->querystr("gender"), "Ů��"))
	{
		say("�Ҳ�����ͽ���㻹��ȥ���Ҽ�λʦ��Ϊʦ�ɡ�", ob);
		SendMenu(ob);
		return;
	}
	
	say("�ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc * npc, CChar * who)
{
        if ( DIFFERSTR(who->querystr("family/family_name"), "ȫ���"))
                return "���뱾�̺��޹ϸ��ҽ̵��书�伮�ɲ��ܽ����㡣";

        if ( npc->query("book_count") < 1)
                return "�������ˣ���������Ѿ�����ȡ���ˡ�";
        
		npc->add("book_count", -1);
        load_item("zhangfapu")->move(who);
        return "�ðɣ��Ȿ��������ס����û�ȥ�ú��ж���";
}

NPCQUANZHEN_END;