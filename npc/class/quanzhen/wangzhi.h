// quanzhen_wangzhi.c ��־̹

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_wangzhi);

virtual void create()
{
	set_name("��־��", "wang zhijian");
	set("gender", "����");
	set("age", 24);
	set("class", "taoist");
	set("long","������ȫ��̵����������еĺ��֣��������ĵ��ӡ�");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("icon",taoist_with_sword);
	set("foolid",51);	
	set("chat_chance_combat", 60);
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	
	set("combat_exp", 160000);
	set("score", 100000);
	
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 100);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("strike",80);

	set_skill("xiantian_qigong", 120);    //��������
	set_skill("quanzhen_jian",120);  //ȫ�潣
	set_skill("jinyan_gong", 100);   //���㹦
	set_skill("haotian_zhang", 120);    //�����

	set_skill("literate",100);
	set_skill("taoism",80);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 3, "����");
	
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];

	if ( ob->query_skill("xiantian_qigong",1) < 35 )
	{
		say("��ı����ڹ��ķ������,�������Ը�������书��", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<3000)
	{
		say("�����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��", ob);
		SendMenu(ob);
		return;
	}
	
	say(" �ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPCQUANZHEN_END;