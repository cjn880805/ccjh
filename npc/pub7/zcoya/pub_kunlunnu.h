// pub_kunlunnu.h ����ū
// dieer 2002-7-27

NPC_BEGIN(CNpub_kunlunnu);

virtual void create()
{
	set_name("����ū", "kunlun nu");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("per",10);
	set("shen_type", 1);
	
	set("str", 44);
	set("int", 44);
	set("con", 44);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 90);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("huntian_qigong", 350);		// ��������
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("xianglong_zhang", 350);		// ����ʮ����
	set_skill("dodge", 350);			// ��������
	set_skill("xiaoyaoyou", 350);			// ��ң��
	set_skill("parry", 350);			// �����м�
	set_skill("claw", 350);		      		// ����צ��
	set_skill("jiuyin_zhua", 350);			// �����׹�צ

	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("claw", "jiuyin_zhua");	        //����NPC�Ļ���צ��װ�������׹�צ
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ�������װ����ң��
	map_skill("parry", "jiuyin_zhua");		//����NPC�Ļ����м�װ�������׹�צ
	map_skill("strike", "xianglong_zhang");		//����NPC�Ļ����Ʒ�װ������ʮ����

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 100);			//����NPC���ӹ�����

	prepare_skill("claw", "jiuyin_zhua");		//����NPC�Ŀ������
	prepare_skill("strike", "xianglong_zhang");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("claw zhua", 1);		//�����׹�צ��������һ��
		break;
	case 1:
		perform_action("strike leiting", 1);	//����ʮ���ƾ�������һ��
		break;
	case 2:
		perform_action("strike xianglong", 1);	//����ʮ���ƾ��н�����
		break;
	case 3:
		perform_action("force shengang", 0);	//�Զ����
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
