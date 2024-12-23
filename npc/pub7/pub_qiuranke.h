// pub_qiuranke.h ��׿�(�������ݳ�)
// dieer 2002-11-24

NPC_BEGIN(CNpub_qiuranke);

virtual void create()
{
	set_name("��׿�", "qiuran ke");
	set("title", "�糾����֮");
	set("gender", "����");
	set("age", 40);
	set("level", 157);

	set("icon",15);				//������������
	set("per",19);
	set("repute", 10000);
	
	set("str", 39);
	set("int", 38);
	set("con", 35);
	set("dex", 30);
	
	set("chat_chance_combat", 20);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);		
	set_skill("yijinjing", 350);	
	set_skill("hand", 350);		
	set_skill("fengyun_shou", 350);		
	set_skill("dodge", 350);			
	set_skill("shaolin_shenfa", 350);	
	set_skill("parry", 350);
	set_skill("blade", 350);		 
	set_skill("dongyangdaofa", 350);
	set_skill("tianluo_diwang", 350);

	map_skill("force", "yijinjing");	
	map_skill("blade", "dongyangdaofa");
	map_skill("dodge", "shaolin_shenfa");	
	map_skill("parry", "dongyangdaofa");
	map_skill("hand", "fengyun_shou");	

	set("apply/armor", 160);
	set("apply/damage", 80);

	prepare_skill("hand", "fengyun_shou");

	carry_object("changpao")->wear();
	carry_object("jiudai");
	carry_object("wodao")->wield();	
	add_money(20000);
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("force powerup", 0);	
		break;
	case 1:
		perform_action("force recover", 0);	
		break;
	case 2:
		perform_action("force recover", 0);	
		break;
	}	
	return 0;
}

NPC_END;