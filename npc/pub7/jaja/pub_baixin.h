//pub_baixin.h ����
//dieer 2002-7-21

NPC_BEGIN(CNpub_baixin);

virtual void create()
{
	set_name("����", "bai xin");
	set("title", "������");
	set("gender", "����");
	set("age", 24);
	set("level", 157);
	set("long", 
		"����Ƥ���ܰף��ڵƹ��¿�������ֱ�׵���͸�������Կ��������Ѫ�����������ְ���Ȼ�ǲ�̬��ȴ�ִ�����˵����������������\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	
	set("str", 34);
	set("int", 35);
	set("con", 35);
	set("dex", 34);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 20);			//����NPC��������
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("zixia_shengong", 350);		// ��ϼ��
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("hunyuan_zhang", 350);		// ��Ԫ��
	set_skill("dodge", 350);			// ��������
	set_skill("huashan_shenfa", 350);		// ��ɽ��
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("huashan_sword", 350);		// ��ɽ����
	set_skill("fanliangyi_dao", 350);		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "huashan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṥװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("sword", "huashan_sword");	//����NPC��ǰʹ�õļ���
	prepare_skill("parry", "fanliangyi_dao");
	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 20);			//����NPC���ӹ�����

	carry_object("sword_1")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword jianzhang", 1);	//��ɽ�������н���������
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
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
