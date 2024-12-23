// pub_lanlinlaoren.h ��������
// dieer 2002-7-29

NPC_BEGIN(CNpub_lanlinlaoren);

virtual void create()
{
	set_name("��������", "lanlin laoren");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 60);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("per",25);	
	set("shen_type", 1);			//����NPC�û�
	
	set("str", 40);
	set("int", 42);
	set("con", 45);
	set("dex", 41);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 100);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("zixia_shengong", 350);		// ��ϼ��
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("hunyuan_zhang", 350);		// ��Ԫ��
	set_skill("dodge", 350);			// ��������
	set_skill("huashan_shenfa", 350);		// ��ɽ��
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);			// ��������
	set_skill("lonely_sword", 350);			// ���¾Ž�

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("strike", "hunyuan_zhang");	        //����NPC�Ļ����Ʒ�Ϊ��Ԫ��
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ�������װ����ɽ��
	map_skill("parry", "lonely_sword");		//����NPC�Ļ����м�װ�����¾Ž�
	map_skill("sword", "lonely_sword");		//����NPC�Ļ�������װ�����¾Ž�

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 40);			//����NPC���ӹ�����

	prepare_skill("strike", "hunyuan_zhang");

	carry_object("changjian")->wield();	

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword pojian", 1);	//���¾Ž��ƽ�
		break;
	case 1:
		perform_action("sword poqi", 1);	//���¾Ž�����
		break;
	case 2:
		perform_action("sword pozhang", 1);	//���¾Ž�����
		break;
	case 3:
		perform_action("strike wuji", 1);	//��Ԫ��(wuji��Ԫ�޼�)
		break;
	case 4:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 5:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
