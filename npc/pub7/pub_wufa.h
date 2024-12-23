// pub_wufa.h �޷�����
// jaja 2002-10-20

NPC_BEGIN(CNpub_wufa);

virtual void create()
{
	set_name("�޷�����", "wu fa");
	set("title", "�޷�����");
	set("gender", "����");
	set("age", 70);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",30);				//������������
	set("repute", -5000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("xiantian_gong", 250);		// ������
	set_skill("sword", 250);			// ��������
	set_skill("quanzhen_jianfa", 250);		// ȫ�潣��
	set_skill("dodge", 250);			// ��������
	set_skill("jinyan_gong", 250);			// ���㹦
	set_skill("parry", 250);			// �����м�
	set_skill("strike", 250);		        // �����Ʒ�
	set_skill("haotian_zhang", 250);		// �����

	map_skill("force", "xiantian_gong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("strike", "haotian_zhang");	        //����NPC�Ļ����Ʒ�װ�������
	map_skill("dodge", "jinyan_gong");		//����NPC�Ļ�������װ�����㹦
	map_skill("parry", "quanzhen_jianfa");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("sword", "quanzhen_jianfa");		//����NPC�Ļ�������װ��ȫ�潣��
	
	prepare_skill("strike", "haotian_zhang");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("changjian")->wield();		//����NPCװ������Ʒ
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword sanqing", 1);	//ȫ�潣��(sanqingһ��������)
		break;
	case 1:
		perform_action("strike ju", 1);		//�����(ju�����۶�)
		break;
	case 2:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 3:
		perform_action("force recover", 0);	//�Զ�����
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