// pub_baoqinguang.h �����
// jaja 2002-10-20

NPC_BEGIN(CNpub_baoqinguang);

virtual void create()
{
	set_name("�����", "bao qinguang");
	set("title", "һ�����");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", -5000);			//����NPC�û�
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("huntian_qigong", 250);		// ��������
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("xianglong_zhang", 250);		// ����ʮ����
	set_skill("dodge", 250);			// ��������
	set_skill("xiaoyaoyou", 250);			// ��ң��
	set_skill("parry", 250);			// �����м�
	set_skill("hand", 250);		        	// �����ַ�
	set_skill("shexing_diaoshou", 250);		// ���ε���

	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("strike", "xianglong_zhang");	        //����NPC�Ļ����Ʒ�װ������ʮ����
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ����Ṧװ����ң��
	map_skill("parry", "xianglong_zhang");		//����NPC�Ļ����м�װ������ʮ����
	map_skill("hand", "shexing_diaoshou");		//����NPC�Ļ����ַ�װ�����ε���

	map_skill("hand", "shexing_diaoshou");		//����NPC�Ŀ�����ȫ
	map_skill("strike", "xianglong_zhang");	


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("strike leiting", 1);	//����ʮ���� ����һ��
		break;
	case 1:
		perform_action("strike xianglong", 1);	//����ʮ���� ������
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
