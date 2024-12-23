// quanzhen_zhangyuan.c ��԰����

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangyuan);

virtual void create()
{
	set_name("��԰����", "zhangyuan" );
	set("gender", "����");
	set("age", 52);
	set("class", "taoist");
	set("long","�����Ƿ���������ʦ��ͯ�ӣ�������ʹ��ˡ�������ʦ�������Ĺ������ͷ�����һ���в��С��԰������ľ��");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);
	set("icon",old_man2);
			set("foolid",49);
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
	set_skill("literate",40);
	set_skill("taoism",30);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 4, "����");
	
	set("book_count",1);
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" �ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPC_END;