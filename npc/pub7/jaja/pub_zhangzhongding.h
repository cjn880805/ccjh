// pub_zhangzhongding.h ���Ҷ�
// dieer 2002-8-10

NPC_BEGIN(CNpub_zhangzhongding);

virtual void create()
{
	set_name("���Ҷ�", "zhang zhongding");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",13);				//������������
	set("per",22);
	
	set("str", 38);
	set("int", 31);
	set("con", 34);
	set("dex", 32);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("xiantian_gong", 350);		// ������
	set_skill("sword", 350);			// ��������
	set_skill("quanzhen_jianfa", 350);		// ȫ�潣��
	set_skill("dodge", 350);			// ��������
	set_skill("jinyan_gong", 350);			// ���㹦
	set_skill("parry", 350);			// �����м�
	set_skill("strike", 350);		        // �����Ʒ�
	set_skill("haotian_zhang", 350);		// �����

	map_skill("force", "xiantian_gong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("strike", "haotian_zhang");	        //����NPC�Ļ����Ʒ�װ�������
	map_skill("dodge", "jinyan_gong");		//����NPC�Ļ�������װ�����㹦
	map_skill("parry", "quanzhen_jianfa");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("sword", "quanzhen_jianfa");		//����NPC�Ļ�������װ��ȫ�潣��

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

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
