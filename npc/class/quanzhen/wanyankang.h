// quanzhen_wanyankang.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_wanyankang);

virtual void create()
{
	set_name("������", "wanyan sou");
	set("gender", "����");
	set("title", "����С��ү");
	set("age", 24);
	set("class", "fighter");
	set("long","���������١���ĸ�����������պ����󣬳���С���ӣ�̰ͼ�����������ġ�");
    set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("per", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("icon",young_man2);
	set("foolid",39);
	set("chat_chance_combat", 60);

	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	set("combat_exp", 160000);
	set("score", 100000);
	
	set_skill("force", 40);
	set_skill("xiantian_qigong", 40);    //��������
	set_skill("sword", 40);
	set_skill("quanzhen_jian",40);  //ȫ�潣
	set_skill("dodge", 40);
	set_skill("jinyan_gong", 40);   //���㹦
	set_skill("parry", 40);
	set_skill("strike",40);
	set_skill("unarmed",40);
	set_skill("haotian_zhang", 40);    //�����
	set_skill("claw",40);
	set_skill("jiuyin_zhua", 40);    //�����
	set_skill("literate",40);
	set_skill("taoism",40);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	map_skill("claw", "jiuyin_zhua");
	prepare_skill("claw", "jiuyin_zhua");
	
	create_family("ȫ���", 3, "����");
	
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
 	
	
	carry_object("changjian")->wield();
	carry_object("male1_cloth")->wear();
	
}
/*	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
			(: perform_action, "strike.ju" :),
			(: perform_action, "sword.ding" :),
	}));
*/	
virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("strike ju", 1);
		break;
	case 2:
		perform_action("sword ding", 1);
		break;
	}

	return 0;
}

NPC_END;